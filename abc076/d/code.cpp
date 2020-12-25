#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> ts(n), vs(n);
    std::vector<int64_t> cum_ts(n + 1);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ts[i];
        cum_ts[i + 1] = ts[i] + cum_ts[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vs[i];
    }

    const int64_t max_t = cum_ts.back();
    double previous_v = 0;
    double ans = 0;
    for (double t = 0; t <= max_t; t += 0.5)
    {
        std::vector<double> tmp(n + 2);
        for (int i = 0; i < n; ++i)
        {
            if (t >= cum_ts[i] && t <= cum_ts[i + 1])
            {
                tmp[i] = vs[i];
            }
            else if (t < cum_ts[i])
            {
                tmp[i] = vs[i] + (cum_ts[i] - t);
            }
            else
            {
                tmp[i] = vs[i] + (t - cum_ts[i + 1]);
            }
        }
        tmp[n] = t;
        tmp[n + 1] = max_t - t;

        const double current_v = *std::min_element(tmp.begin(), tmp.end());

        ans += 0.5 * (previous_v + current_v) * 0.5;
        previous_v = current_v;
    }

    std::cout << std::setprecision(18) << ans << std::endl;
    return 0;
}
