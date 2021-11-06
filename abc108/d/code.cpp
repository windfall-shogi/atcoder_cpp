#include <iostream>
#include <vector>

struct Edge
{
    int s, t;
    int w;
};

int main()
{
    int l;
    std::cin >> l;

    int p = 1;
    int tmp = 2;
    while (true)
    {
        if (tmp * 2 <= l)
        {
            tmp *= 2;
            ++p;
        }
        else
        {
            break;
        }
    }

    const int n = p + 1; // node数
    std::vector<Edge> edges;
    edges.reserve(60);
    for (int i = 1; i < n; ++i)
    {
        edges.emplace_back(Edge{i, i + 1, 1 << (i - 1)});
        edges.emplace_back(Edge{i, i + 1, 0});
    }

    for (int i = n - 1; i >= 1; --i)
    {
        const int k = 1 << (i - 1);
        if (tmp + k <= l)
        {
            edges.emplace_back(Edge{i, n, tmp});
            tmp += k;
        }
    }

    std::cout << n << ' ' << edges.size() << std::endl;
    for (const auto &e : edges)
    {
        std::cout << e.s << ' ' << e.t << ' ' << e.w << std::endl;
    }

    return 0;
}
