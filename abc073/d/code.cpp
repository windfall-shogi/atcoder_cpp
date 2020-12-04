#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <climits>
#include <unordered_map>
#include <algorithm>

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
            return static_cast<int64_t>(x.first) * k + x.second;
        }
    };
} // namespace std
using Graph = std::vector<std::vector<std::pair<int, int>>>;

std::vector<int> ComputeDistances(const Graph &graph, const int start)
{
    std::vector<int> d(graph.size(), std::numeric_limits<int>::max());
    d[start] = 0;
    std::stack<int> s;
    s.push(start);
    while (!s.empty())
    {
        const int current = s.top();
        s.pop();

        for (const auto &e : graph[current])
        {
            if (d[current] + e.second < d[e.first])
            {
                d[e.first] = d[current] + e.second;
                s.push(e.first);
            }
        }
    }

    return d;
}

int main()
{
    int n, m, r;
    std::cin >> n >> m >> r;
    std::vector<int> cities(r);
    for (int i = 0; i < r; ++i)
    {
        std::cin >> cities[i];
        --cities[i];
    }
    Graph graph(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        --a;
        --b;
        graph[a].emplace_back(std::make_pair(b, c));
        graph[b].emplace_back(std::make_pair(a, c));
    }

    std::unordered_map<std::pair<int, int>, int> map;
    for (const auto i : cities)
    {
        const auto d = ComputeDistances(graph, i);
        for (const auto j : cities)
        {
            const auto p = std::make_pair(i, j);
            const auto q = std::make_pair(j, i);
            map[p] = d[j];
            map[q] = d[j];
        }
    }

    std::sort(cities.begin(), cities.end());
    int ans = std::numeric_limits<int>::max();
    do
    {
        int sum = 0;
        for (int i = 1; i < r; ++i)
        {
            const auto p = std::make_pair(cities[i - 1], cities[i]);
            sum += map[p];
        }
        if (sum < ans)
        {
            ans = sum;
        }
    } while (std::next_permutation(cities.begin(), cities.end()));

    std::cout << ans << std::endl;
    return 0;
}
