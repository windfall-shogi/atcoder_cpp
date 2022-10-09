#include <iostream>
#include <vector>

int main()
{
    constexpr int64_t MOD = 1000000007;
    int n, k;
    std::cin >> n >> k;

    std::vector<int> count;
    for (int i = 1; i <= n;)
    {
        const int j = n / i;
        if (i <= j)
        {
            count.emplace_back(1);
            ++i;
        }
        else
        {
            count.emplace_back(n / j + 1 - i);
            i = n / j + 1;
        }
    }

    const auto size = count.size();
    std::vector<int64_t> current(size), next(size);
    current[0] = 1;
    for (int i = 0; i < k; ++i)
    {
        std::vector<int64_t> buffer(size);
        for (size_t j = 0; j < size; ++j)
        {
            if (j == 0)
            {
                buffer[j] = current[j];
            }
            else
            {
                buffer[j] = (buffer[j - 1] + current[j]) % MOD;
            }
        }

        for (size_t j = 0; j < size; ++j)
        {
            next[j] = buffer[size - 1 - j] * count[j] % MOD;
        }
        next.swap(current);
    }

    int64_t ans = 0;
    for (const auto v : current)
    {
        ans += v;
        ans %= MOD;
    }
    std::cout << ans << std::endl;

    return 0;
}
