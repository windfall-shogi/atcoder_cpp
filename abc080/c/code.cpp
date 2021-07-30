#include <iostream>
#include <limits>

int F[100][10];
int P[100][11];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            std::cin >> F[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            std::cin >> P[i][j];
        }
    }

    int32_t ans = std::numeric_limits<int32_t>::min();
    for (int i = 1; i < (1 << 10); ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            int c = 0;
            for (int k = 0; k < 10; ++k)
            {
                if (F[j][k] && i & (1 << k))
                {
                    ++c;
                }
            }
            sum += P[j][c];
        }

        ans = std::max(ans, sum);
    }

    std::cout << ans << std::endl;
    return 0;
}
