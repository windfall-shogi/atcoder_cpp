#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    int64_t n;
    std::array<int64_t, 5> xs;
    std::cin >> n;
    for (size_t i = 0; i < xs.size(); ++i)
    {
        std::cin >> xs[i];
    }

    int64_t t, bottleneck;
    for (size_t i = 0; i < xs.size(); ++i)
    {
        if (i == 0)
        {
            t = (n + xs[i] - 1) / xs[i];
            bottleneck = xs[i];
        }
        else
        {
            if (xs[i] >= bottleneck)
            {
                t = t + 1;
            }
            else
            {
                t = (n + xs[i] - 1) / xs[i] + i;
                bottleneck = xs[i];
            }
        }
    }

    std::cout << t << std::endl;
    return 0;
}
