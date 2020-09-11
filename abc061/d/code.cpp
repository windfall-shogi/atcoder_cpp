#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <numeric>

int main()
{
    int n, m;
    std::cin >> n >> m;

    constexpr int64_t inf = 1ull << 60;

    std::vector<int64_t> dist(n, inf);
    dist[0] = 0;
    std::vector<std::unordered_map<int64_t, int64_t>> edge(n);

    std::vector<bool> loop(n, false);

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        --a;
        --b;
        edge[a][b] = -c;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (dist[j] == inf)
            {
                continue;
            }
            for (const auto e : edge[j])
            {
                dist[e.first] = std::min(dist[e.first], dist[j] + e.second);
            }
        }
    }
    const auto ans = -dist[n - 1];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (dist[j] == inf)
            {
                continue;
            }
            for (const auto e : edge[j])
            {
                if (dist[j] + e.second < dist[e.first])
                {
                    dist[e.first] = dist[j] + e.second;
                    loop[e.first] = true;
                }
                if (loop[j])
                {
                    loop[e.first] = true;
                }
            }
        }
    }

    if (loop[n - 1])
    {
        std::cout << "inf" << std::endl;
    }
    else
    {
        std::cout << ans << std::endl;
    }
    return 0;
}
