#include <iostream>
#include <vector>

int main()
{
    constexpr int M = static_cast<int>(1e9) + 7;

    int h, w, a, b;
    std::cin >> h >> w >> a >> b;

    std::vector<int> upper(w, 1), lower(w, 0);
    for (int i = 1; i < h; ++i)
    {
        lower[0] = 1;
        if (i > h - a - 1)
        {
            std::fill(lower.begin(), lower.begin() + b, -1);
        }
        for (int j = 1; j < w; ++j)
        {
            if (lower[j] < 0)
            {
                continue;
            }
            if (lower[j - 1] < 0)
            {
                lower[j] = upper[j];
            }
            else
            {
                lower[j] = (upper[j] + lower[j - 1]) % M;
            }
        }
        upper.swap(lower);
    }

    std::cout << upper.back() << std::endl;

    return 0;
}
