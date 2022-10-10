#include <iostream>

int main()
{
    int l, r;
    std::cin >> l >> r;
    int ans;
    if (r - l > 2019)
    {
        ans = 0;
    }
    else
    {
        ans = 2019;
        for (int i = l; i < r; ++i)
        {
            for (int j = i + 1; j <= r; ++j)
            {
                const auto tmp = static_cast<int64_t>(i) * j % 2019;
                if (tmp < ans)
                {
                    ans = tmp;
                }
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
