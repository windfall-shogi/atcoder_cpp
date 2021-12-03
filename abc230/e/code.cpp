#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int64_t> divisor(const int64_t n)
{
    std::vector<int64_t> r;
    for (int64_t i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            r.emplace_back(i);
            if (i * i != n)
            {
                r.emplace_back(n / i);
            }
        }
    }

    std::sort(r.begin(), r.end());
    return r;
}

int main()
{
    int64_t N;
    std::cin >> N;

    if (N == 1)
    {
        std::cout << 1 << std::endl;
        return 0;
    }

    const std::vector<int64_t> d = divisor(N);
    int64_t ans = N;
    for (int64_t i = 1; i < static_cast<int64_t>(d.size()); ++i)
    {
        const int64_t k = N / d[i];
        ans += k * (d[i] - d[i - 1]);
    }

    std::cout << ans << std::endl;

    return 0;
}
