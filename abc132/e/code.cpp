#include <iostream>
#include <stack>
#include <array>
#include <vector>

constexpr int INF = 1000000;

struct Data
{
    std::array<int, 3> d;

    Data()
    {
        std::fill(d.begin(), d.end(), INF);
    }
};

using Edges = std::vector<int>;
using Graph = std::vector<Edges>;

int main()
{
    int n, m;
    std::cin >> n >> m;
    Graph graph(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        graph[u].emplace_back(v);
    }
    int s, t;
    std::cin >> s >> t;
    --s;
    --t;

    std::vector<Data> distances(n);
    distances[s].d[0] = 0;
    std::stack<int> stack;
    stack.emplace(s);
    while (!stack.empty())
    {
        const int current = stack.top();
        stack.pop();
        for (const auto next : graph[current])
        {
            bool updated = false;
            for (int i = 0; i < 3; ++i)
            {
                if (distances[current].d[i] + 1 < distances[next].d[(i + 1) % 3])
                {
                    updated = true;
                    distances[next].d[(i + 1) % 3] = distances[current].d[i] + 1;
                }
            }
            if (updated)
            {
                stack.emplace(next);
            }
        }
    }

    if (distances[t].d[0] == INF)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << distances[t].d[0] / 3 << std::endl;
    }
    return 0;
}
