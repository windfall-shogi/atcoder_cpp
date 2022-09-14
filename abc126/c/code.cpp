#include <iostream>
#include <iomanip>

int main()
{
    int n, k;
    std::cin >> n >> k;
    double ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int d = i;
        double p = 1.0 / n;
        while (d < k)
        {
            d *= 2;
            p *= 0.5;
        }
        ans += p;
    }

    std::cout << std::setprecision(14) << ans << std::endl;
    return 0;
}
