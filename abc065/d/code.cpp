#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

//https://algo-logic.info/kruskal-mst/

/* UnionFind：素集合系管理の構造体(union by rank)
    isSame(x, y): x と y が同じ集合にいるか。 計算量はならし O(α(n))
    unite(x, y): x と y を同じ集合にする。計算量はならし O(α(n))
*/
struct UnionFind
{ // The range of node number is u 0 v n-1
    std::vector<int> rank, parents;
    UnionFind() {}
    UnionFind(int n)
    { // make n trees.
        rank.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            makeTree(i);
        }
    }
    void makeTree(int x)
    {
        parents[x] = x; // the parent of x is x
        rank[x] = 0;
    }
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    void unite(int x, int y)
    {
        x = findRoot(x);
        y = findRoot(y);
        if (rank[x] > rank[y])
        {
            parents[y] = x;
        }
        else
        {
            parents[x] = y;
            if (rank[x] == rank[y])
            {
                rank[y]++;
            }
        }
    }
    int findRoot(int x)
    {
        if (x != parents[x])
            parents[x] = findRoot(parents[x]);
        return parents[x];
    }
};
// 辺の定義
struct Edge
{
    int64_t u;
    int64_t v;
    int64_t cost;
};
bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; } // 辺を直接比較するための関数
/* Kruskal :クラスカル法で minimum spanning tree を求める構造体
    入力: 辺のvector, 頂点数V
    最小全域木の重みの総和: sum
    計算量: O(|E|log|V|)
*/
struct Kruskal
{
    UnionFind uft;
    int64_t sum; // 最小全域木の重みの総和
    std::vector<Edge> edges;
    int V;
    Kruskal(const std::vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); }
    void init()
    {
        sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
        uft = UnionFind(V);
        sum = 0;
        for (auto e : edges)
        {
            if (!uft.isSame(e.u, e.v))
            { // 閉路にならなければ加える
                uft.unite(e.u, e.v);
                sum += e.cost;
            }
        }
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> xs(n), ys(n);

    std::vector<std::pair<int64_t, int64_t>> tmp_x(n), tmp_y(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> xs[i] >> ys[i];

        tmp_x[i] = std::make_pair(xs[i], i);
        tmp_y[i] = std::make_pair(ys[i], i);
    }
    std::sort(tmp_x.begin(), tmp_x.end());
    std::sort(tmp_y.begin(), tmp_y.end());

    const auto f_cost = [&](const int64_t i, const int64_t j) {
        return std::min(std::abs(xs[i] - xs[j]), std::abs(ys[i] - ys[j]));
    };

    std::vector<Edge> edges;
    for (int i = 0; i < n - 1; ++i)
    {
        Edge e_x = {tmp_x[i].second, tmp_x[i + 1].second, f_cost(tmp_x[i].second, tmp_x[i + 1].second)};
        Edge e_y = {tmp_y[i].second, tmp_y[i + 1].second, f_cost(tmp_y[i].second, tmp_y[i + 1].second)};
        edges.push_back(e_x);
        edges.push_back(e_y);
    }

    Kruskal krs(edges, n);
    std::cout << krs.sum << std::endl;

    return 0;
}
