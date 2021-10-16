#include <iostream>

int main()
{
    char table[50][50];

    int h, w;
    std::cin >> h >> w;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            std::cin >> table[i][j];
        }
    }

    bool flag = true;
    constexpr int dx[4] = {+1, 0, -1, 0};
    constexpr int dy[4] = {0, +1, 0, -1};
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (table[i][j] != '#')
            {
                continue;
            }

            bool tmp = false;
            for (int k = 0; k < 4; ++k)
            {
                const int x = j + dx[k], y = i + dy[k];
                if (x < 0 || x >= w || y < 0 || y >= h)
                {
                    continue;
                }
                if (table[y][x] == '#')
                {
                    tmp = true;
                    break;
                }
            }

            if (!tmp)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }

    std::cout << (flag ? "Yes" : "No") << std::endl;

    return 0;
}
