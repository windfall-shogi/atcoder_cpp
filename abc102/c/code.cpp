#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
        as[i] -= i + 1;
    }
    std::sort(as.begin(), as.end());

    const auto b = as[n / 2];
    int64_t ans = 0;
    for (const auto a : as)
    {
        ans += std::abs(a - b);
    }

    std::cout << ans << std::endl;

    return 0;
}
