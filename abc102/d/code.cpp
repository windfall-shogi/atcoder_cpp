#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    std::vector<int64_t> cum_sum(n);
    std::partial_sum(as.begin(), as.end(), cum_sum.begin());

    int64_t ans = std::numeric_limits<int64_t>::max();
    int left = 0, right = 2;
    int64_t p, q, r, s;
    for (int middle = 1; middle < n - 2; ++middle)
    {
        p = cum_sum[left], q = cum_sum[middle] - cum_sum[left];
        while (left + 1 < middle)
        {
            const int64_t tmp_p = cum_sum[left + 1], tmp_q = cum_sum[middle] - cum_sum[left + 1];
            if (std::abs(p - q) > std::abs(tmp_p - tmp_q))
            {
                p = tmp_p;
                q = tmp_q;

                ++left;
            }
            else
            {
                break;
            }
        }

        r = cum_sum[right] - cum_sum[middle], s = cum_sum[n - 1] - cum_sum[right];
        if (right == middle)
        {
            right = middle + 1;
        }
        while (right + 1 < n - 1)
        {
            const int64_t tmp_r = cum_sum[right + 1] - cum_sum[middle], tmp_s = cum_sum[n - 1] - cum_sum[right + 1];
            if (std::abs(r - s) > std::abs(tmp_r - tmp_s))
            {
                r = tmp_r;
                s = tmp_s;

                ++right;
            }
            else
            {
                break;
            }
        }

        std::vector<int64_t> buffer{p, q, r, s};
        std::sort(buffer.begin(), buffer.end());
        ans = std::min(ans, buffer.back() - buffer.front());
    }

    std::cout << ans << std::endl;

    return 0;
}
