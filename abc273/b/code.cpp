#include <iostream>

int main()
{
    int64_t x, k;
    std::cin >> x >> k;
    int64_t factor = 1;
    for (int64_t i = 0; i < k; ++i)
    {
        x = (x + 5 * factor) / (10 * factor) * (10 * factor);
        factor *= 10;
    }
    std::cout << x << std::endl;
    return 0;
}
