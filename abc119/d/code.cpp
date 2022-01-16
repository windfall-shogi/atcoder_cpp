#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

std::pair<int64_t, int64_t> get_distance(const int64_t x, const std::vector<int64_t> &vs)
{
    if (x < vs.front())
    {
        return std::make_pair(static_cast<int64_t>(1) << 50, vs.front() - x);
    }
    else if (x >= vs.back())
    {
        return std::make_pair(x - vs.back(), static_cast<int64_t>(1) << 50);
    }
    else
    {
        const auto it = std::lower_bound(vs.begin(), vs.end(), x);
        const auto i = std::distance(vs.begin(), it);
        return std::make_pair(x - vs[i - 1], vs[i] - x);
    }
}

int main()
{
    int64_t a, b, q;
    std::cin >> a >> b >> q;
    std::vector<int64_t> ss(a), ts(b), xs(q);
    for (int64_t i = 0; i < a; ++i)
    {
        std::cin >> ss[i];
    }
    for (int64_t i = 0; i < b; ++i)
    {
        std::cin >> ts[i];
    }
    for (int64_t i = 0; i < q; ++i)
    {
        std::cin >> xs[i];
    }

    for (int64_t i = 0; i < q; ++i)
    {
        const auto d1 = get_distance(xs[i], ss);
        const auto d2 = get_distance(xs[i], ts);

        const int64_t ans = std::min({std::max(d1.first, d2.first),
                                      std::max(d1.second, d2.second),
                                      d1.first + d2.second + std::min(d1.first, d2.second),
                                      d1.second + d2.first + std::min(d1.second, d2.first)});
        std::cout << ans << std::endl;
    }
    return 0;
}
