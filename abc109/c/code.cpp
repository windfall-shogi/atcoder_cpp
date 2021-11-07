#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int n, x;
    std::cin >> n >> x;
    std::vector<int64_t> xs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> xs[i];
        xs[i] = std::abs(xs[i] - x);
    }

    if (n == 1)
    {
        std::cout << xs[0] << std::endl;
        return 0;
    }

    // xs are non-zero.
    int64_t gcd = std::gcd(xs[0], xs[1]);
    for (int i = 2; i < n; ++i)
    {
        gcd = std::gcd(gcd, xs[i]);
        if (gcd == 1)
        {
            break;
        }
    }

    std::cout << gcd << std::endl;

    return 0;
}
