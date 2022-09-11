#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> xs;
    for (int64_t i = 0; i < xs.size(); ++i)
    {
        std::cin >> xs[i];
    }

    int last_i = 0, k = 10;
    for (int64_t i = 0; i < xs.size(); ++i)
    {
        const auto tmp = xs[i] % 10;
        if (tmp == 0)
        {
            continue;
        }
        if (tmp < k)
        {
            k = tmp;
            last_i = i;
        }
    }

    int ans = 0;
    for (int64_t i = 0; i < xs.size(); ++i)
    {
        if (i == last_i)
        {
            ans += xs[i];
        }
        else
        {
            ans += (xs[i] + 9) / 10 * 10;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
