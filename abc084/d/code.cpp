#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

constexpr int N = 100002;
std::array<bool, N> PRIMES;
std::array<int, N> COUNT;

bool check(const int x)
{
    return PRIMES[x] && PRIMES[(x + 1) / 2];
}

void initialize()
{
    std::fill(PRIMES.begin(), PRIMES.end(), true);
    PRIMES[0] = PRIMES[1] = false;
    for (int i = 2; i * i < N; ++i)
    {
        if (!PRIMES[i])
        {
            continue;
        }
        for (int j = 2 * i; j < N; j += i)
        {
            PRIMES[j] = false;
        }
    }

    COUNT[0] = 0;
    for (int i = 1; i < N; ++i)
    {
        COUNT[i] = COUNT[i - 1] + (check(i) ? 1 : 0);
    }
}

int main()
{
    int q;
    std::cin >> q;
    std::vector<int> ls(q), rs(q);
    for (int i = 0; i < q; ++i)
    {
        std::cin >> ls[i] >> rs[i];
    }

    initialize();

    for (int i = 0; i < q; ++i)
    {
        std::cout << COUNT[rs[i]] - COUNT[ls[i] - 1] << std::endl;
    }

    return 0;
}
