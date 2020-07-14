#include <iostream>
#include <vector>
#include <algorithm>

constexpr int N = 40 + 1;
constexpr int M = (N - 1) * 10 + 1;
constexpr int INF = 1000000;
int table[N][M][M];

int main()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                table[i][j][k] = INF;
            }
        }
    }

    int n, ma, mb;
    std::cin >> n >> ma >> mb;
    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        a[i] = x;
        b[i] = y;
        c[i] = z;
    }

    table[0][0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                table[i + 1][j][k] = std::min(table[i + 1][j][k], table[i][j][k]);
                if (j + a[i] < M && k + b[i] < M)
                {
                    table[i + 1][j + a[i]][k + b[i]] = std::min(table[i + 1][j + a[i]][k + b[i]], table[i][j][k] + c[i]);
                }
            }
        }
    }

    int cost = INF;
    for (int j = 1; j < M; ++j)
    {
        for (int k = 1; k < M; ++k)
        {
            if (j * mb == k * ma)
            {
                cost = std::min(cost, table[n][j][k]);
            }
        }
    }
    if (cost >= INF)
    {
        cost = -1;
    }

    std::cout << cost << std::endl;
    return 0;
}
