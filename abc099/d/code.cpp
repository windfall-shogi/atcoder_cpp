#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

constexpr int MAX_N = 500;
constexpr int MAX_C = 30;

int64_t cost[MAX_C][MAX_C];

int main()
{
    int n, c;
    std::cin >> n >> c;
    for (int i = 0; i < c; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            std::cin >> cost[i][j];
        }
    }
    std::vector<std::vector<int64_t>> table(3);
    for (auto &v : table)
    {
        v.resize(c);
        std::fill(v.begin(), v.end(), 0);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int color;
            std::cin >> color;
            --color;

            ++table[(i + j) % 3][color];
        }
    }

    int64_t ans = std::numeric_limits<int64_t>::max();
    for (int c1 = 0; c1 < c; ++c1)
    {
        int64_t cost1 = 0;
        for (int i = 0; i < c; ++i)
        {
            cost1 += cost[i][c1] * table[0][i];
        }
        for (int c2 = 0; c2 < c; ++c2)
        {
            if (c2 == c1)
            {
                continue;
            }
            int64_t cost2 = 0;
            for (int i = 0; i < c; ++i)
            {
                cost2 += cost[i][c2] * table[1][i];
            }

            for (int c3 = 0; c3 < c; ++c3)
            {
                if (c3 == c1 || c3 == c2)
                {
                    continue;
                }

                int64_t cost3 = 0;
                for (int i = 0; i < c; ++i)
                {
                    cost3 += cost[i][c3] * table[2][i];
                }

                const int64_t total = cost1 + cost2 + cost3;
                if (total < ans)
                {
                    ans = total;
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
