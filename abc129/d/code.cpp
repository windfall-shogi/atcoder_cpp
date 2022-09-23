#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum Direction
{
    U,
    D,
    L,
    R,
    SIZE
};

int table[SIZE][2002][2002];

int main()
{
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> ss(h);
    for (int i = 0; i < h; ++i)
    {
        std::cin >> ss[i];
    }

    const auto f = [&](const Direction d, const int i, const int j, int &count)
    {
        if (ss[i][j] == '#')
        {
            table[d][i][j] = 0;
            count = 0;
        }
        else
        {
            table[d][i][j] = count;
            ++count;
        }
    };

    // U
    for (int j = 0; j < w; ++j)
    {
        int count = 0;
        for (int i = 0; i < h; ++i)
        {
            f(U, i, j, count);
        }
    }
    // D
    for (int j = 0; j < w; ++j)
    {
        int count = 0;
        for (int i = h - 1; i >= 0; --i)
        {
            f(D, i, j, count);
        }
    }
    // L
    for (int i = 0; i < h; ++i)
    {
        int count = 0;
        for (int j = 0; j < w; ++j)
        {
            f(L, i, j, count);
        }
    }
    // R
    for (int i = 0; i < h; ++i)
    {
        int count = 0;
        for (int j = w - 1; j >= 0; --j)
        {
            f(R, i, j, count);
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            int tmp = 0;
            for (int k = 0; k < SIZE; ++k)
            {
                tmp += table[k][i][j];
            }
            // ランプのマス
            tmp += 1;

            ans = std::max(ans, tmp);
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
