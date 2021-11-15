#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<int, int> factorize(const int n)
{
    std::unordered_map<int, int> m;
    for (int x = 2; x <= n; ++x)
    {
        int tmp = x;
        while (tmp % 2 == 0)
        {
            ++m[2];
            tmp /= 2;
        }
        for (int k = 3; k <= tmp; k += 2)
        {
            while (tmp % k == 0)
            {
                ++m[k];
                tmp /= k;
            }
        }
    }
    return m;
}

int main()
{
    int n;
    std::cin >> n;

    std::unordered_map<int, int> m = factorize(n);
    std::vector<int> count3, count5, count15, count25, count75;
    for (const auto &e : m)
    {
        const int x = e.first;
        const int c = e.second;
        if (c >= 2)
        {
            count3.emplace_back(x);
        }
        if (c >= 4)
        {
            count5.emplace_back(x);
        }
        if (c >= 14)
        {
            count15.emplace_back(x);
        }
        if (c >= 24)
        {
            count25.emplace_back(x);
        }
        if (c >= 74)
        {
            count75.emplace_back(x);
        }
    }

    int ans = 0;
    for (const auto i : count3)
    {
        for (auto it_j = count5.begin(); it_j != count5.end(); ++it_j)
        {
            const auto j = *it_j;
            if (i == j)
            {
                continue;
            }
            for (auto it_k = it_j + 1; it_k != count5.end(); ++it_k)
            {
                const auto k = *it_k;
                if (i == k || j == k)
                {
                    continue;
                }
                ++ans;
            }
        }
        for (const auto j : count25)
        {
            if (i != j)
            {
                ++ans;
            }
        }
    }
    for (const auto i : count5)
    {
        for (const auto j : count15)
        {
            if (i != j)
            {
                ++ans;
            }
        }
    }
    ans += count75.size();

    std::cout << ans << std::endl;

    return 0;
}
