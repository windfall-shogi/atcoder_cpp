#include <iostream>
#include <cmath>

int64_t f(const int64_t b, const int64_t n)
{
    if (n < b)
    {
        return n;
    }
    else
    {
        return f(b, n / b) + (n % b);
    }
}

int main()
{
    int64_t n, s;
    std::cin >> n >> s;

    if (s == n)
    {
        // この場合は自明
        std::cout << n + 1 << std::endl;
        return 0;
    }
    else if (s > n)
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    // bが大きいほうが各桁が大きくなるので、和も大きくなる傾向にある
    // ただし、単調ではないので、全探索になる
    //
    // sqrt(n) < b <= nで2桁のb進数になる
    // p,qを使って、n = p*b + q, s = p + q
    // n = p*b + s - p
    // n - s = p*(b - 1)
    // b = (n - s) / p + 1
    // また、n = p*b + q >= p*b > p^2
    // p < sqrt(n)
    //
    // 同様に3桁の場合も考えられるが、手間なうえに計算量はあまり減らないようなのであまり意味はない
    // よって、sqrt(n)まで全探索し、残りは2桁の場合を考える

    const int64_t sqrt_n = std::sqrt(n);
    for (int64_t b = 2; b <= sqrt_n; ++b)
    {
        if (f(b, n) == s)
        {
            std::cout << b << std::endl;
            return 0;
        }
    }

    // bの最小値なので、pを上から調べる
    for (int64_t p = sqrt_n; p >= 1; --p)
    {
        if ((n - s) % p)
        {
            continue;
        }
        const int64_t b = (n - s) / p + 1;
        if (b >= sqrt_n && b >= 2 && f(b, n) == s)
        {
            std::cout << b << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}
