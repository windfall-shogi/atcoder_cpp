#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    std::vector<int64_t> cum_sum(n + 1), cum_xor(n + 1);
    cum_sum[0] = cum_xor[0] = 0;
    std::partial_sum(as.begin(), as.end(), ++cum_sum.begin());
    std::partial_sum(as.begin(), as.end(), ++cum_xor.begin(), std::bit_xor<int64_t>());

    int64_t ans = 0;
    for (int l = 1; l <= n; ++l)
    {
        int ok = l, ng = n + 1;
        while (ok + 1 != ng)
        {
            const int mid = (ok + ng) / 2;

            const auto s = cum_sum[mid] - cum_sum[l - 1];
            const auto x = cum_xor[mid] ^ cum_xor[l - 1];
            if (s == x)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        ans += ok - l + 1;
    }

    std::cout << ans << std::endl;

    return 0;
}
