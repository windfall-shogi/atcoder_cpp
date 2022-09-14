#include <iostream>
#include <vector>

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
        int rx = root(x); // xの根をrx
        int ry = root(y); // yの根をry
        if (rx == ry)
            return; // xとyの根が同じ(=同じ木にある)時はそのまま

        // 要素数を移し替える
        count[ry] += count[rx];
        count[rx] = 0;

        parent[rx] = ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
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

int main()
{
    int n, m;
    std::cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        --x;
        --y;
        uf.unite(x, y);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i == uf.root(i))
        {
            ++ans;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
