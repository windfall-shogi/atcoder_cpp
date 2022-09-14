#include <iostream>

int main()
{
    int64_t m, k;
    std::cin >> m >> k;

    if (m == 0)
    {
        if (k == 0)
        {
            std::cout << "0 0" << std::endl;
        }
        else
        {
            std::cout << -1 << std::endl;
        }
        return 0;
    }
    else if (m == 1)
    {
        if (k == 0)
        {
            std::cout << "0 0 1 1" << std::endl;
        }
        else
        {
            std::cout << -1 << std::endl;
        }
        return 0;
    }
    else if (k >= (1LL << m))
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    const int64_t p = 1LL << m;
    for (int64_t i = 0; i < p; ++i)
    {
        if (i != k)
        {
            std::cout << i << ' ';
        }
    }
    std::cout << k << ' ';
    for (int64_t i = p - 1; i >= 0; --i)
    {
        if (i != k)
        {
            std::cout << i << ' ';
        }
    }
    std::cout << k << std::endl;

    return 0;
}
