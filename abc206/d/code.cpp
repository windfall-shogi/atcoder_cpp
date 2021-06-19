#include <iostream>
#include <unordered_set>
#include <vector>

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

    int getCount(int x)
    {
        return count[root(x)];
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    if (n == 1)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    constexpr int max_size = 200000 + 10;
    UnionFind uf(max_size);
    for (size_t i = 0; i < as.size() / 2; ++i)
    {
        int p = as[i];
        int q = as[as.size() - i - 1];
        if (p == q)
        {
            continue;
        }

        uf.unite(p, q);
    }

    int count = 0;
    for (int i = 0; i < max_size; ++i)
    {
        if (uf.root(i) == i)
        {
            count += uf.getCount(i) - 1;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
