#include <iostream>
#include <vector>
#include <algorithm>

int check(const int d, const std::vector<int> &as, const std::vector<int> &bs)
{
    const uint32_t mask = 1 << d;

    std::vector<int> buffer_a(as.size());
    std::transform(as.begin(), as.end(), buffer_a.begin(), [mask](const int a)
                   { return a & (2 * mask - 1); });

    std::vector<int> buffer_b[2];
    for (size_t i = 0; i < bs.size(); ++i)
    {
        const auto b = bs[i] & (2 * mask - 1);
        if (b & mask)
        {
            buffer_b[1].emplace_back(b - mask);
        }
        else
        {
            buffer_b[0].emplace_back(b);
        }
    }
    for (int i = 0; i < 2; ++i)
    {
        std::sort(buffer_b[i].begin(), buffer_b[i].end());
    }

    int count = 0;
    for (int a : buffer_a)
    {
        if (a & mask)
        {
            a -= mask;

            // aを足しても繰り上がりしない
            const int c1 = std::distance(buffer_b[0].begin(),
                                         std::lower_bound(buffer_b[0].begin(), buffer_b[0].end(), mask - a));
            // aを足したら繰り上がる
            const int c2 = std::distance(buffer_b[1].begin(),
                                         std::lower_bound(buffer_b[1].begin(), buffer_b[1].end(), mask - a));

            count += c1 + buffer_b[1].size() - c2;
        }
        else
        {
            // aを足しても繰り上がりしない
            const int c1 = std::distance(buffer_b[0].begin(),
                                         std::lower_bound(buffer_b[0].begin(), buffer_b[0].end(), mask - a));
            // aを足したら繰り上がる
            const int c2 = std::distance(buffer_b[1].begin(),
                                         std::lower_bound(buffer_b[1].begin(), buffer_b[1].end(), mask - a));

            count += buffer_b[0].size() - c1 + c2;
        }
    }

    return count & 0x1;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> as(n), bs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> bs[i];
    }

    int ans = 0;
    for (int i = 0; i <= 28; ++i)
    {
        ans |= check(i, as, bs) << i;
    }
    std::cout << ans << std::endl;
    return 0;
}
