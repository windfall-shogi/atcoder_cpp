#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int64_t> buffer(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> buffer[i];
    }

    int64_t ans = 0;
    std::vector<int64_t> negative_l, negative_r;
    negative_l.reserve(n);
    negative_r.reserve(n);
    int64_t tmp_l = 0;
    for (int l = 0; l <= std::min(n, k); ++l)
    {
        if (l > 0)
        {
            if (buffer[l - 1] > 0)
            {
                tmp_l += buffer[l - 1];
            }
            else
            {
                negative_l.emplace_back(buffer[l - 1]);
            }
        }

        for (int r = 0; r <= std::min(n - l, k - l); ++r)
        {
            negative_r.clear();
            std::copy(negative_l.begin(), negative_l.end(), std::back_inserter(negative_r));
            int64_t tmp_r = tmp_l;
            for (int i = 0; i < r; ++i)
            {
                if (buffer[n - 1 - i] > 0)
                {
                    tmp_r += buffer[n - 1 - i];
                }
                else
                {
                    negative_r.emplace_back(buffer[n - 1 - i]);
                }
            }

            std::sort(negative_r.rbegin(), negative_r.rend());
            int b = k - (l + r);
            while (!negative_r.empty() && b > 0)
            {
                negative_r.pop_back();
                --b;
            }
            for (const int64_t v : negative_r)
            {
                tmp_r += v;
            }

            ans = std::max(ans, tmp_r);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
