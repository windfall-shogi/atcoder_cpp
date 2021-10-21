#include <iostream>

int main()
{
    int d, n;
    std::cin >> d >> n;
    int ans = n;
    if (n == 100)
    {
        ans = 101;
    }
    for (int i = 0; i < d; ++i)
    {
        ans *= 100;
    }
    std::cout << ans << std::endl;
    return 0;
}
