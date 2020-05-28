#include <iostream>

int main()
{
    int n, k, x, y;
    std::cin >> n >> k >> x >> y;

    if (n <= k)
    {
        std::cout << x * n << std::endl;
    }
    else
    {
        std::cout << x * k + y * (n - k) << std::endl;
    }
    return 0;
}
