#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;

    for (int x = n; x <= m; ++x)
    {
        if (m % x == 0)
        {
            std::cout << m / x << std::endl;
            return 0;
        }
    }

    std::cout << 1 << std::endl;
    return 0;
}
