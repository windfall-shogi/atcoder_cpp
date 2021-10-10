#include <iostream>

int main()
{
    int64_t n, k;
    std::cin >> n >> k;

    int64_t ans = 0;
    if (k == 0)
    {
        ans = n * n;
    }
    else
    {
        for (int b = k + 1; b <= n; ++b)
        {
            ans += n / b * (b - k);
            if (n % b >= k)
            {
                ans += n % b - k + 1;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
