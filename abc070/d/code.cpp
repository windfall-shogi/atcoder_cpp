#include <iostream>
#include <vector>
#include <limits>
#include <stack>

struct Edge
{
    int source, target;
    int64_t cost;

    Edge() = default;
    Edge(const int s, const int t, const int64_t c) : source(s), target(t), cost(c) {}
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<Edge>> nodes(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int64_t a, b, c;
        std::cin >> a >> b >> c;
        --a;
        --b;
        nodes[a].emplace_back(a, b, c);
        nodes[b].emplace_back(b, a, c);
    }
    int q, k;
    std::cin >> q >> k;
    --k;
    std::vector<int64_t> d(n, std::numeric_limits<int64_t>::max());
    d[k] = 0;
    std::stack<Edge> stack;
    for (const auto &e : nodes[k])
    {
        stack.emplace(e);
    }

    while (!stack.empty())
    {
        const Edge e = stack.top();
        stack.pop();

        if (d[e.target] > d[e.source] + e.cost)
        {
            d[e.target] = d[e.source] + e.cost;

            for (const auto &f : nodes[e.target])
            {
                if (f.target != e.source)
                {
                    stack.emplace(f);
                }
            }
        }
    }

    std::vector<int64_t> ans(q);
    for (int i = 0; i < q; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        --x;
        --y;

        ans[i] = d[x] + d[y];
    }

    for (int i = 0; i < q; ++i)
    {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}
