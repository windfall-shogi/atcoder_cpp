#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> a(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    int m = 0;
    std::vector<std::pair<int, int>> ops;

    const auto it_max = std::max_element(a.begin(), a.end());
    const auto it_min = std::min_element(a.begin(), a.end());
    const int64_t max = *it_max, min = *it_min;

    // trueなら全部が正、falseなら全部が負
    bool flag;

    if (max <= 0)
    {
        flag = false;
    }
    else if (min >= 0)
    {
        flag = true;
    }
    else if (std::abs(max) > std::abs(min))
    {
        const auto d = std::distance(a.begin(), it_max);
        for (int i = 0; i < n; ++i)
        {
            ++m;
            ops.emplace_back(d, i);
        }
        flag = true;
    }
    else
    {
        const auto d = std::distance(a.begin(), it_min);
        for (int i = 0; i < n; ++i)
        {
            ++m;
            ops.emplace_back(d, i);
        }
        flag = false;
    }

    if (flag)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            ++m;
            ops.emplace_back(i, i + 1);
        }
    }
    else
    {
        for (int i = n - 1; i > 0; --i)
        {
            ++m;
            ops.emplace_back(i, i - 1);
        }
    }

    std::cout << m << std::endl;
    for (const auto &e : ops)
    {
        std::cout << e.first + 1 << ' ' << e.second + 1 << std::endl;
    }

    return 0;
}
