#include <iostream>

constexpr int MAX_SIZE = 200000;
int as[MAX_SIZE], bs[MAX_SIZE];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> bs[i];
    }

    uint64_t ans = 0;
    for (int i = 0; i < n / 2; ++i)
    {
        const uint64_t v = (static_cast<uint64_t>(as[2 * i]) << 32) | as[2 * i + 1];
        for (int j = 0; j < n; ++j)
        {
            const uint64_t u = (static_cast<uint64_t>(bs[j]) << 32) | bs[j];

            ans ^= u + v;
        }
    }
    if (n % 2 == 1)
    {
        const uint64_t v = (static_cast<uint64_t>(as[n - 1]) << 32) | as[n - 1];
        for (int j = 0; j < n / 2; ++j)
        {
            const uint64_t u = (static_cast<uint64_t>(bs[2 * j]) << 32) | bs[2 * j + 1];

            ans ^= u + v;
        }

        ans ^= as[n - 1] + bs[n - 1];
    }

    const uint32_t ans32 = static_cast<uint32_t>(ans >> 32) ^ (ans & 0xFFFFFFFF);
    std::cout << ans32 << std::endl;
    return 0;
}
