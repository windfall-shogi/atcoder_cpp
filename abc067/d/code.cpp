#include <iostream>
#include <stack>
#include <vector>

std::vector<int> ComputeDistance(const std::vector<std::vector<int>> &edges, const int start)
{
    std::vector<int> d(edges.size(), 2 * edges.size());
    d[start] = 0;
    std::stack<int> stack;
    stack.push(start);
    while (!stack.empty())
    {
        const int current = stack.top();
        stack.pop();
        for (const auto node : edges[current])
        {
            if (d[current] < d[node])
            {
                d[node] = d[current] + 1;
                stack.push(node);
            }
        }
    }

    return d;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        edges[a - 1].emplace_back(b - 1);
        edges[b - 1].emplace_back(a - 1);
    }

    const auto black_distance = ComputeDistance(edges, 0);
    const auto white_distance = ComputeDistance(edges, n - 1);

    int black = 0, white = 0;
    for (int i = 0; i < n; ++i)
    {
        if (black_distance[i] <= white_distance[i])
        {
            ++black;
        }
        else
        {
            ++white;
        }
    }

    if (black <= white)
    {
        std::cout << "Snuke" << std::endl;
    }
    else
    {
        std::cout << "Fennec" << std::endl;
    }
    return 0;
}
