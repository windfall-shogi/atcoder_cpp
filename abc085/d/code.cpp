#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using Pair = std::pair<int64_t, int64_t>;
using Vector = std::vector<Pair>;

int64_t solve(const int64_t h, const Vector &vec)
{
    const int64_t a_max = std::max_element(vec.begin(), vec.end(),
                                           [](const Pair &a, const Pair &b)
                                           {
                                               return a.second < b.second;
                                           })
                              ->second;

    int64_t damage = 0;
    int64_t count = 0;
    for (const auto &e : vec)
    {
        if (e.first < a_max)
        {
            break;
        }

        damage += e.first;
        ++count;

        if (damage >= h)
        {
            return count;
        }
    }

    count += (h - damage + a_max - 1) / a_max;
    return count;
}

int main()
{
    int64_t n, h;
    std::cin >> n >> h;
    Vector vec;
    vec.reserve(n);
    for (int64_t i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        vec.emplace_back(b, a);
    }
    std::sort(vec.begin(), vec.end(), std::greater<Pair>());

    
    const auto ans = solve(h, vec);
    std::cout << ans << std::endl;
    return 0;
}
