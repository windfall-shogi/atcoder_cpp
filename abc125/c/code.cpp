#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    std::vector<int64_t> ls(n), rs(n);
    ls[0] = as[0];
    rs[n - 1] = as[n - 1];
    for (int i = 1; i < n; ++i)
    {
        ls[i] = std::gcd(ls[i - 1], as[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        rs[i] = std::gcd(rs[i + 1], as[i + 1]);
    }

    int64_t ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int64_t g;
        if (i == 0)
        {
            g = rs[i];
        }
        else if (i == n - 1)
        {
            g = ls[i];
        }
        else
        {
            g = std::gcd(ls[i], rs[i]);
        }
        ans = std::max(ans, g);
    }
    std::cout << ans << std::endl;
    return 0;
}
