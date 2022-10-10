#include <iostream>
#include <vector>
#include <queue>

using Edges = std::vector<int>;
using Graph = std::vector<Edges>;

int main()
{
    constexpr int MOD = 1000000007;
    int n, k;
    std::cin >> n >> k;
    Graph graph(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    for (int i = 0; i < n; ++i)
    {
        if (graph[i].size() >= k)
        {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    std::vector<bool> checked(n);
    checked[0] = true;
    std::queue<int> queue;
    queue.emplace(0);
    Graph graph2(n);
    while (!queue.empty())
    {
        const auto current = queue.front();
        queue.pop();
        for (const auto next : graph[current])
        {
            if (!checked[next])
            {
                checked[next] = true;
                queue.emplace(next);
                graph2[current].emplace_back(next);
            }
        }
    }

    queue.emplace(0);
    int64_t ans = k;
    while (!queue.empty())
    {
        const auto current = queue.front();
        queue.pop();
        for (size_t i = 0; i < graph2[current].size(); ++i)
        {
            const auto node = graph2[current][i];
            if (current == 0)
            {
                ans *= k - 1 - i;
            }
            else
            {
                ans *= k - 2 - i;
            }
            ans %= MOD;
            queue.emplace(node);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
