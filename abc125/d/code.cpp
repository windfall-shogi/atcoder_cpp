#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> as(n), bs(n);
    int plus = 0, minus = 0, zero = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
        bs[i] = std::abs(as[i]);

        if (as[i] == 0)
        {
            ++zero;
        }
        else if (as[i] > 0)
        {
            ++plus;
        }
        else
        {
            ++minus;
        }
    }
    int64_t ans = std::accumulate(bs.begin(), bs.end(), 0LL);

    if (zero == 0 && minus % 2 == 1)
    {
        const auto it = std::min_element(bs.begin(), bs.end());
        ans -= 2 * *it;
    }

    std::cout << ans << std::endl;
    return 0;
}
