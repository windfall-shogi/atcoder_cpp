#include <iostream>

int64_t TABLE[1001][10001];

int main()
{
    int H, W, h1, w1, h2, w2;
    std::cin >> H >> W >> h1 >> w1 >> h2 >> w2;
    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            std::cin >> TABLE[i][j];
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
        for (int j = 1; j < W; ++j)
        {
            TABLE[i][j + 1] += TABLE[i][j];
        }
    }
    for (int j = 1; j <= W; ++j)
    {
        for (int i = 1; i < H; ++i)
        {
            TABLE[i + 1][j] += TABLE[i][j];
        }
    }

    int64_t ans = 0;
    for (int i = 1; i + h1 - 1 <= H; ++i)
    {
        for (int j = 1; j + w1 - 1 <= W; ++j)
        {
            const auto i1 = i - 1, j1 = j - 1;
            const auto i2 = i + h1 - 1, j2 = j + w1 - 1;
            const int64_t tmp1 = TABLE[i2][j2] + TABLE[i1][j1] - TABLE[i2][j1] - TABLE[i1][j2];

            int64_t tmp_ans = 0;
            for (int s = 1; s + h2 - 1 <= h1; ++s)
            {
                for (int t = 1; t + w2 - 1 <= w1; ++t)
                {
                    const auto s1 = s - 1 + i - 1, t1 = t - 1 + j - 1;
                    const auto s2 = s + h2 - 1 + i - 1, t2 = t + w2 - 1 + j - 1;
                    const int64_t tmp2 = TABLE[s2][t2] + TABLE[s1][t1] - TABLE[s2][t1] - TABLE[s1][t2];

                    tmp_ans = std::max(tmp_ans, tmp2);
                }
            }

            ans = std::max(ans, tmp1 - tmp_ans);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
