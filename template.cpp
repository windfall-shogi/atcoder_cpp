#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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

    UnionFind(int n) : parent(n)
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
        return parent[x] = root(parent[x]);
    }

    // xとyの木を併合
    void unite(int x, int y)
    {
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry)
            return;      //xとyの根が同じ(=同じ木にある)時はそのまま
        parent[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    // 2つのデータx, yが属する木が同じならtrueを返す
    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
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
