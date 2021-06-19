#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

constexpr int32_t MOD = 1000000007;

namespace std
{
    template <>
    class hash<std::pair<int, int>>
    {
    public:
        size_t operator()(const std::pair<int, int> &x) const
        {
            // 10^9
            constexpr int k = 1000000000;
            // hash<int>::operator()がとても遅い
            return static_cast<int64_t>(x.first) * k + x.second;
        }
    };
} // namespace std

struct UnionFind
{
    std::vector<int> parent; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    std::vector<int> count;

    UnionFind(int n) : parent(n), count(n, 1)
    {
        //最初は全てが根であるとして初期化
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    int root(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        const int p = root(parent[x]);
        if (p != parent[x])
        {
            // まだ書き換えが済んでいない部分について木の根に要素数を移し替える
            count[p] += count[parent[x]];
            count[parent[x]] = 0;
        }
        return parent[x] = p;
    }

    // xとyの木を併合
    void unite(int x, int y)
    {
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry)
            return; //xとyの根が同じ(=同じ木にある)時はそのまま

        // 要素数を移し替える
        count[ry] += count[rx];
        count[rx] = 0;

        parent[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    // 2つのデータx, yが属する木が同じならtrueを返す
    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    // xが属する木の要素数を返す
    int getCount(int x)
    {
        return count[root(x)];
    }
};

// https://drken1215.hatenablog.com/entry/2018/06/08/210000
constexpr int MAX = 310000;
// 上で定義している
// constexpr int MOD = 1000000007;

int64_t fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
int64_t COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

struct Edge
{
    int to;
    int cost;
};

// <最短距離, 頂点の番号>
using Node = std::pair<int, int>;
using Graph = std::vector<std::vector<Edge>>;

constexpr int32_t INF = 1000000000;

// ダイクストラ法でstartから各頂点までの最短距離を計算する
std::vector<int> RunDijkstra(const Graph &graph, const int start)
{
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> queue;
    std::vector<int> d(graph.size(), INF);
    d[start] = 0;
    queue.emplace(0, start);

    while (!queue.empty())
    {
        const Node node = queue.top();
        queue.pop();
        const int node_index = node.second;
        if (d[node_index] < node.first)
        {
            continue;
        }

        for (const auto &edge : graph[node_index])
        {
            if (d[edge.to] > d[node_index] + edge.cost)
            {
                d[edge.to] = d[node_index] + edge.cost;
                queue.emplace(d[edge.to], edge.to);
            }
        }
    }

    return d;
}
