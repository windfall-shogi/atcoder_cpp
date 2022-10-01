#include <iostream>
#include <vector>
#include <utility>
#include <limits>

struct Data
{
    int B, C, index;
};

using Edges = std::vector<Data>;
using Graph = std::vector<Edges>;

void solve(const Graph &graph, const std::vector<std::vector<int>> &es,
           const int city, const int index, const int64_t cost, int64_t &ans, std::vector<bool> &history)
{
    if (city == static_cast<int>(graph.size()) - 1)
    {
        ans = std::min(ans, cost);
        return;
    }

    for (const auto &p : graph[city])
    {
        const auto next_city = p.B;
        if (history[next_city])
        {
            continue;
        }
        const auto path_index = p.index;
        for (const auto q : es[path_index])
        {
            if (q > index)
            {
                history[next_city] = true;
                solve(graph, es, next_city, q, cost + p.C, ans, history);
                history[next_city] = false;
                break;
            }
        }
    }
}

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    Graph graph(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        --a;
        --b;
        graph[a].emplace_back(Data{b, c, i});
    }
    std::vector<std::vector<int>> es(m);
    for (int i = 0; i < k; ++i)
    {
        int e;
        std::cin >> e;
        --e;
        es[e].emplace_back(i);
    }

    int64_t ans = std::numeric_limits<int64_t>::max();
    std::vector<bool> history(n);
    history[0] = true;
    solve(graph, es, 0, -1, 0, ans, history);
    if (ans == std::numeric_limits<int64_t>::max())
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << ans << std::endl;
    }
    return 0;
}
