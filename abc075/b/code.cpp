#include <iostream>
#include <vector>
#include <string>

int main()
{
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> a(h);
    for (int i = 0; i < h; ++i)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (a[i][j] == '#')
            {
                continue;
            }

            int n = 0;
            for (int p : {-1, 0, 1})
            {
                for (int q : {-1, 0, 1})
                {
                    if (p == 0 && q == 0)
                    {
                        continue;
                    }

                    if (i + p < 0 || i + p >= h || j + q < 0 || j + q >= w)
                    {
                        continue;
                    }
                    if (a[i + p][j + q] == '#')
                    {
                        ++n;
                    }
                }
            }
            a[i][j] = '0' + static_cast<char>(n);
        }
    }

    for (int i = 0; i < h; ++i)
    {
        std::cout << a[i] << std::endl;
    }
    return 0;
}
