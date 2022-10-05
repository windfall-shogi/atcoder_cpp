#include <iostream>
#include <vector>
#include <utility>

int main()
{
    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> edges;
    for (int i = 1; i < N; ++i)
    {
        edges.emplace_back(0, i);
    }
    int k = (N - 1) * (N - 2) / 2;
    if (K > k)
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (k == K)
            {
                break;
            }
            edges.emplace_back(i, j);
            --k;
        }
        if (k == K)
        {
            break;
        }
    }

    std::cout << edges.size() << std::endl;
    for (const auto &e : edges)
    {
        std::cout << e.first + 1 << ' ' << e.second + 1 << std::endl;
    }
    return 0;
}
