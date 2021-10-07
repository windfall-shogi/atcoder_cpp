#include <iostream>
#include <vector>

int TABLE[2][2001][2001] = {0};
enum Color
{
    BLACK,
    WHITE
};

int main()
{
    int n, k;
    std::cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        int x, y;
        char c;
        std::cin >> x >> y >> c;

        const Color color = c == 'B' ? BLACK : WHITE;
        if (color == WHITE)
        {
            y += k;
        }

        x %= 2 * k;
        y %= 2 * k;

        const int type = (x / k + y / k) % 2;

        if (x >= k)
        {
            x -= k;
        }
        if (y >= k)
        {
            y -= k;
        }

        for (int v = 0; v < 3; ++v)
        {
            const int tmp_y = y + v * k;
            const int min_y = std::max(tmp_y - k + 1, 0);
            const int max_y = std::min(tmp_y + 1, 2000);
            for (int u = 0; u < 3; ++u)
            {
                const int tmp_x = x + u * k;
                if ((tmp_x / k + tmp_y / k) % 2 != type)
                {
                    continue;
                }
                const int min_x = std::max(tmp_x - k + 1, 0);
                const int max_x = std::min(tmp_x + 1, 2000);

                TABLE[color][min_y][min_x] += 1;
                TABLE[color][min_y][max_x] -= 1;
                TABLE[color][max_y][min_x] -= 1;
                TABLE[color][max_y][max_x] += 1;
            }
        }
    }

    for (int c = 0; c < 2; ++c)
    {
        for (int y = 0; y < 2 * k + 1; ++y)
        {
            for (int x = 1; x < 2 * k + 1; ++x)
            {
                TABLE[c][y][x] += TABLE[c][y][x - 1];
            }
        }
        for (int y = 1; y < 2 * k + 1; ++y)
        {
            for (int x = 0; x < 2 * k + 1; ++x)
            {
                TABLE[c][y][x] += TABLE[c][y - 1][x];
            }
        }
    }

    int ans = 0;
    for (int y = 0; y < 2 * k; ++y)
    {
        for (int x = 0; x < 2 * k; ++x)
        {
            const int bs = TABLE[BLACK][y][x];
            const int ws = TABLE[WHITE][y][x];
            ans = std::max(bs + ws, ans);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
