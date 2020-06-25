#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <queue>

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

struct Edge
{
    int to;
    int cost;
};

// <最短距離, 頂点の番号>
using Node = std::pair<int, int>;
using Graph = std::vector<std::vector<Edge>>;

constexpr int32_t INF = 1000000000;

std::vector<int> RunDijkstra(const Graph &graph, const int start)
{
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> queue;
    std::vector<int> d(graph.size(), INF);
    d[start] = 0;
    queue.emplace(0, start);

    while (!queue.empty())
    {
        const Node node = queue.top();
        queue.pop();
        const int node_index = node.second;
        if (d[node_index] < node.first)
        {
            continue;
        }

        for (const auto &edge : graph[node_index])
        {
            if (d[edge.to] > d[node_index] + edge.cost)
            {
                d[edge.to] = d[node_index] + edge.cost;
                queue.emplace(d[edge.to], edge.to);
            }
        }
    }

    return d;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    Graph graph(n);

    // エッジが使用されているかを記録
    std::unordered_map<std::pair<int, int>, bool> edge_list;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        --a;
        --b;
        graph[a].emplace_back(Edge{b, c});
        graph[b].emplace_back(Edge{a, c});

        if (a < b)
        {
            edge_list[std::make_pair(a, b)] = false;
        }
        else
        {
            edge_list[std::make_pair(b, a)] = false;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        const auto distance = RunDijkstra(graph, i);
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                continue;
            }

            for (const auto &edge : graph[j])
            {
                if (distance[j] == distance[edge.to] + edge.cost)
                {
                    // このエッジは最短経路の一部
                    if (j < edge.to)
                    {
                        edge_list[std::make_pair(j, edge.to)] = true;
                    }
                    else
                    {
                        edge_list[std::make_pair(edge.to, j)] = true;
                    }
                }
            }
        }
    }

    int count = 0;
    for (const auto &e : edge_list)
    {
        if (!e.second)
        {
            ++count;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
