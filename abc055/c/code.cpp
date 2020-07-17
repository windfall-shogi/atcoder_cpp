#include <iostream>

int main()
{
    int64_t n, m;
    std::cin >> n >> m;

    int64_t sum = 0;
    if (n >= m / 2)
    {
        sum = m / 2;
    }
    else
    {
        sum = n;

        m -= 2 * n;
        sum += m / 4;
    }

    std::cout << sum << std::endl;
    return 0;
}
