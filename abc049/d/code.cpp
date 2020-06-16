#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <map>

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

namespace std
{
    template <>
    class hash<std::pair<int, int>>
    {
    public:
        size_t operator()(const std::pair<int, int> &x) const
        {
            // この計算がとても遅い
            return hash<int>()(x.first) ^ hash<int>()(x.second);
        }
    };
} // namespace std

int main()
{
    int n, k, l;
    std::cin >> n >> k >> l;

    UnionFind u1(n), u2(n);
    for (int i = 0; i < k; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;

        u1.unite(a, b);
    }
    for (int i = 0; i < l; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;

        u2.unite(a, b);
    }

    // unordered_mapの方がmapより速い
    std::unordered_map<int64_t, int> counter;
    for (int i = 0; i < n; ++i)
    {
        const int index1 = u1.root(i), index2 = u2.root(i);
        const auto p = static_cast<int64_t>(index1) * n + index2;
        ++counter[p];
    }

    for (int i = 0; i < n; ++i)
    {
        const int index1 = u1.root(i), index2 = u2.root(i);
        const auto p = static_cast<int64_t>(index1) * n + index2;

        std::cout << counter[p];
        if (i == n - 1)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << ' ';
        }
    }

    return 0;
}
