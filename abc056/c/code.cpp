#include <iostream>
#include <cmath>

int main()
{
    int x;
    std::cin >> x;
    // (1 + N) * N / 2 >= x
    // (M + 0.5) * (M - 0.5) >= 2 * x
    // M^2 >= 2 * x - 0.25
    // N >= (2 * x - 0.25)^0.5 - 0.5

    std::cout << static_cast<int32_t>(std::ceil(std::sqrt(2 * x - 0.25) - 0.5)) << std::endl;
    return 0;
}
