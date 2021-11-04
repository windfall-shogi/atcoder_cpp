#include <iostream>

char TABLE[100][100];

int main()
{
    int h, w;
    std::cin >> h >> w;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            std::cin >> TABLE[i][j];
        }
    }

    for (int i = 0; i < h; ++i)
    {
        bool flag = true;
        for (int j = 0; j < w; ++j)
        {
            if (TABLE[i][j] == '#')
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            for (int j = 0; j < w; ++j)
            {
                TABLE[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < w; ++j)
    {
        bool flag = true;
        for (int i = 0; i < h; ++i)
        {
            if (TABLE[i][j] == '#')
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            for (int i = 0; i < h; ++i)
            {
                TABLE[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < h; ++i)
    {
        bool flag = false;
        for (int j = 0; j < w; ++j)
        {
            if (TABLE[i][j] != 0)
            {
                std::cout << TABLE[i][j];
                flag = true;
            }
        }
        if (flag)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}
