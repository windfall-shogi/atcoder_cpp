#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    int64_t ans = 0;
    for (const auto a : as)
    {
        ans += a - 1;
    }

    std::cout << ans << std::endl;

    return 0;
}
