#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <utility>

using Graph = std::vector<std::unordered_set<int>>;

bool IsConnected(const Graph &graph)
{
    std::vector<bool> visited(graph.size(), false);
    std::stack<int> s;
    s.push(0);

    while (!s.empty())
    {
        const auto node = s.top();
        s.pop();
        visited[node] = true;

        for (const auto i : graph[node])
        {
            if (visited[i])
            {
                continue;
            }
            s.push(i);
        }
    }

    for (const bool b : visited)
    {
        if (!b)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    Graph graph(n);
    std::vector<std::pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        edges[i] = std::make_pair(a, b);
        graph[a].emplace(b);
        graph[b].emplace(a);
    }

    int count = 0;
    for (const auto &e : edges)
    {
        if (graph[e.first].size() == 1 || graph[e.second].size() == 1)
        {
            ++count;
            continue;
        }
        graph[e.first].erase(e.second);
        graph[e.second].erase(e.first);

        const bool c = IsConnected(graph);
        if (!c)
        {
            ++count;
        }

        graph[e.first].emplace(e.second);
        graph[e.second].emplace(e.first);
    }

    std::cout << count << std::endl;
    return 0;
}
