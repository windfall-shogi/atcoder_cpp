#include <iostream>

int64_t pow_(const int64_t x, const int64_t p, const int64_t mod)
{
    if (p == 0)
    {
        return 1;
    }
    else if (p % 2 == 1)
    {
        return pow_(x % mod, p - 1, mod) * (x % mod) % mod;
    }
    else
    {
        const auto tmp = pow_(x % mod, p / 2, mod);
        return tmp * tmp % mod;
    }
}

int64_t f(const int64_t n, const int64_t base, const int64_t mod)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n % 2 == 1)
    {
        const auto k = n - 1;
        const auto tmp = f(k, base, mod);
        return (tmp * (base % mod) + 1) % mod;
    }
    else
    {
        const auto k = n / 2;
        const auto tmp = f(k, base, mod);
        return (tmp * pow_(base, k, mod) + tmp) % mod;
    }
}

int64_t g(const int64_t n, const int64_t base, const int64_t b, const int64_t mod)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n % 2 == 1)
    {
        const auto k = n - 1;
        const auto tmp = g(k, base, b, mod);
        return (tmp * (base % mod) + b * k) % mod;
    }
    else
    {
        const auto k = n / 2;
        const auto tmp = g(k, base, b, mod);
        return (tmp * pow_(base % mod, k, mod) % mod + tmp + b * k % mod * f(k, base, mod) % mod) % mod;
    }
}

int main()
{
    int64_t l, a, b, m;
    std::cin >> l >> a >> b >> m;

    int64_t ans = 0;
    int64_t left = 1, right = left * 10;
    int64_t a2 = a;
    int64_t base = 10;
    for (int d = 1; d <= 18; ++d)
    {
        if (a2 < right)
        {
            const int64_t n = std::min((right - a2 + b - 1) / b, l);

            ans *= pow_(base, n, m);
            ans %= m;
            ans += (a2 % m) * f(n, base, m) % m;
            ans %= m;
            ans += g(n, base, b, m);
            ans %= m;

            a2 += n * b;
            l -= n;
        }

        base *= 10;
        base %= m;
        left *= 10;
        right *= 10;
        if (l <= 0)
        {
            break;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
