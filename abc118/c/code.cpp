#include <iostream>
#include <numeric>

int main()
{
    int n;
    std::cin >> n;
    int a1, a2;
    std::cin >> a1 >> a2;
    int ans = std::gcd(a1, a2);
    for (int i = 2; i < n; ++i)
    {
        int a;
        std::cin >> a;
        ans = std::gcd(ans, a);
    }

    std::cout << ans << std::endl;

    return 0;
}
