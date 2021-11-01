#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int64_t> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    std::unordered_map<int64_t, int64_t> counter;
    int64_t tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        tmp += as[i];
        tmp %= m;
        ++counter[tmp];
    }

    int64_t ans = 0;
    for (const auto &e : counter)
    {
        if (e.first == 0)
        {
            ans += (e.second + 1) * e.second / 2;
        }
        else
        {
            ans += (e.second - 1) * e.second / 2;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
