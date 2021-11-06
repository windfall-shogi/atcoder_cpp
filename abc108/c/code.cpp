#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;

    const int64_t tmp = n / k;
    int64_t ans = tmp * tmp * tmp;
    if (k % 2 == 0)
    {
        const int64_t tmp2 = (n + k / 2) / k;
        ans += tmp2 * tmp2 * tmp2;
    }

    std::cout << ans << std::endl;

    return 0;
}
