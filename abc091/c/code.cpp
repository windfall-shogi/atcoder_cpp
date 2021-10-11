#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

// Dinic's maximum flow
// https://github.com/spaghetti-source/algorithm/blob/master/graph/maximum_flow_dinic.cc
constexpr int64_t INF = (1ll << 50);
struct Graph
{
    using FlowType = int64_t;
    struct edge
    {
        int src, dst;
        FlowType capacity, flow;
        size_t rev;
    };
    int n;
    std::vector<std::vector<edge>> adj;
    Graph(int n) : n(n), adj(n) {}
    void add_edge(int src, int dst, FlowType capacity)
    {
        adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
        adj[dst].push_back({dst, src, 0, 0, adj[src].size() - 1});
    }
    FlowType max_flow(int s, int t)
    {
        std::vector<int> level(n), iter(n);
        std::function<int(void)> levelize = [&]() { // foward levelize
            level.assign(n, -1);
            level[s] = 0;
            std::queue<int> Q;
            Q.push(s);
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                if (u == t)
                    break;
                for (auto &e : adj[u])
                {
                    if (e.capacity > e.flow && level[e.dst] < 0)
                    {
                        Q.push(e.dst);
                        level[e.dst] = level[u] + 1;
                    }
                }
            }
            return level[t];
        };
        std::function<FlowType(int, FlowType)> augment = [&](int u, FlowType cur)
        {
            if (u == t)
                return cur;
            for (int &i = iter[u]; i < adj[u].size(); ++i)
            {
                edge &e = adj[u][i], &r = adj[e.dst][e.rev];
                if (e.capacity > e.flow && level[u] < level[e.dst])
                {
                    FlowType f = augment(e.dst, std::min(cur, e.capacity - e.flow));
                    if (f > 0)
                    {
                        e.flow += f;
                        r.flow -= f;
                        return f;
                    }
                }
            }
            return FlowType(0);
        };
        for (int u = 0; u < n; ++u) // initialize
            for (auto &e : adj[u])
                e.flow = 0;

        FlowType flow = 0;
        while (levelize() >= 0)
        {
            std::fill(iter.begin(), iter.end(), 0);
            for (FlowType f; (f = augment(s, INF)) > 0;)
                flow += f;
        }
        return flow;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> reds, blues;
    reds.reserve(n);
    blues.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        reds.emplace_back(a, b);
    }
    for (int i = 0; i < n; ++i)
    {
        int c, d;
        std::cin >> c >> d;
        blues.emplace_back(c, d);
    }

    // 0: source
    // 1~n: red
    // n+1~2n: blue
    // 2n+1: sink
    Graph g(2 * n + 2);
    for (int i = 0; i < n; ++i)
    {
        g.add_edge(0, i + 1, 1);
        g.add_edge(i + n + 1, 2 * n + 1, 1);
    }
    std::sort(reds.begin(), reds.end());
    std::sort(blues.begin(), blues.end());
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            if (reds[i].first >= blues[j].first)
            {
                break;
            }
            if (reds[i].second < blues[j].second)
            {
                g.add_edge(i + 1, j + n + 1, 1);
            }
        }
    }

    std::cout << g.max_flow(0, 2 * n + 1) << std::endl;
    return 0;
}
