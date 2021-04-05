#include <iostream>
#include <vector>

using Graph = std::vector<std::vector<int>>;

std::vector<int> GetDistances(const Graph &graph)
{
    std::vector<int> d(10);
    for (int j = 0; j < 10; ++j)
    {
        d[j] = graph[j][1];
    }

    for (int n = 0; n < 10; ++n)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (j == 1)
            {
                continue;
            }
            for (int k = 0; k < 10; ++k)
            {
                if (k == 1 || j == k)
                {
                    continue;
                }

                if (d[j] > graph[j][k] + d[k])
                {
                    d[j] = graph[j][k] + d[k];
                }
            }
        }
    }

    return d;
}

int main()
{
    int h, w;
    std::cin >> h >> w;

    std::vector<std::vector<int>> c(10);
    for (int i = 0; i < 10; ++i)
    {
        c[i].reserve(10);
        for (int j = 0; j < 10; ++j)
        {
            int tmp;
            std::cin >> tmp;
            c[i].emplace_back(tmp);
        }
    }
    const std::vector<int> d = GetDistances(c);

    std::vector<int64_t> count(10);
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            int tmp;
            std::cin >> tmp;
            if (tmp != -1)
            {
                ++count[tmp];
            }
        }
    }

    int64_t sum = 0;
    for (int i = 0; i < 10; ++i)
    {
        sum += count[i] * d[i];
    }

    std::cout << sum << std::endl;
    return 0;
}
