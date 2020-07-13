#include <iostream>
#include <vector>

using Edges = std::vector<int>;
using Graph = std::vector<Edges>;

int Search(const Graph &edge_list, std::vector<bool> &visited,
           const int depth, const int current_node)
{
    if (static_cast<size_t>(depth) == edge_list.size())
    {
        return 1;
    }

    int n = 0;
    for (const int next : edge_list[current_node])
    {
        if (visited[next])
        {
            continue;
        }
        visited[next] = true;
        n += Search(edge_list, visited, depth + 1, next);
        visited[next] = false;
    }
    return n;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    Graph edge_list(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        edge_list[a].push_back(b);
        edge_list[b].push_back(a);
    }

    std::vector<bool> visited(n);
    visited[0] = true;
    int count = Search(edge_list, visited, 1, 0);

    std::cout << count << std::endl;

    return 0;
}
