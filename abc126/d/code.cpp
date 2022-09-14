#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <stack>

int main()
{
    int n;
    std::cin >> n;
    std::unordered_map<int, std::vector<std::pair<int, int64_t>>> graph;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        int64_t w;
        std::cin >> u >> v >> w;
        --u;
        --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    std::vector<int> ans(n, -1);
    std::stack<int> stack;
    ans[0] = 0;
    for (const auto &e : graph[0])
    {
        stack.push(e.first);
    }
    while (!stack.empty())
    {
        int node = stack.top();
        stack.pop();
        for (const auto &e : graph[node])
        {
            if (ans[e.first] != -1)
            {
                ans[node] = ans[e.first] ^ (e.second % 2);
            }
            else
            {
                if (ans[e.first] == -1)
                {
                    stack.push(e.first);
                }
            }
        }
    }

    for (const auto v : ans)
    {
        std::cout << v << std::endl;
    }
    return 0;
}
