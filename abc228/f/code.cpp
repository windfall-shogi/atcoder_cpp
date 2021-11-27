#include <iostream>

constexpr int MAX_SIZE = 1001;
int64_t A[MAX_SIZE][MAX_SIZE];
int64_t SUM[MAX_SIZE][MAX_SIZE];
int64_t BUF1[MAX_SIZE][MAX_SIZE];
int64_t BUF2[MAX_SIZE][MAX_SIZE];
int64_t M[MAX_SIZE][MAX_SIZE];

int main()
{
    int H, W, h1, w1, h2, w2;
    std::cin >> H >> W >> h1 >> w1 >> h2 >> w2;
    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            std::cin >> A[i][j];
        }
    }

    if (h2 > h1)
    {
        h2 = h1;
    }
    if (w2 > w1)
    {
        w2 = w1;
    }
    if (h2 >= h1 && w2 >= w1)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            SUM[i][j] = SUM[i][j - 1] + SUM[i - 1][j] - SUM[i - 1][j - 1] + A[i][j];
        }
    }

    // SUMの方は右下の座標を基準にした方が綺麗に書ける
    // BUFの方は左上を基準にする
    for (int i = h1; i <= H; ++i)
    {
        for (int j = w1; j <= W; ++j)
        {
            BUF1[i - h1 + 1][j - w1 + 1] = SUM[i][j] + SUM[i - h1][j - w1] - SUM[i][j - w1] - SUM[i - h1][j];
        }
    }
    for (int i = h2; i <= H; ++i)
    {
        for (int j = w2; j <= W; ++j)
        {
            BUF2[i - h2 + 1][j - w2 + 1] = SUM[i][j] + SUM[i - h2][j - w2] - SUM[i][j - w2] - SUM[i - h2][j];
        }
    }

    for (int i = 1; i + h2 - 1 <= H; ++i)
    {
        for (int j = 1; j + w2 - 1 <= W; ++j)
        {
            M[i][j] = BUF2[i][j];
        }

        // 範囲をスライドさせながらmax
        int K = w1 - w2;
        while (K > 0)
        {
            const int d = (K + 1) / 2;
            for (int j = 1; j + w2 - 1 + d <= W; ++j)
            {
                M[i][j] = std::max(M[i][j], M[i][j + d]);
            }
            K -= d;
        }
    }
    for (int j = 1; j + w2 - 1 <= W; ++j)
    {
        int K = h1 - h2;
        while (K > 0)
        {
            const int d = (K + 1) / 2;
            for (int i = 1; i + h2 - 1 + d <= H; ++i)
            {
                M[i][j] = std::max(M[i][j], M[i + d][j]);
            }
            K -= d;
        }
    }

    int64_t ans = 0;
    for (int i = 1; i + h1 - 1 <= H; ++i)
    {
        for (int j = 1; j + w1 - 1 <= W; ++j)
        {
            ans = std::max(ans, BUF1[i][j] - M[i][j]);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
