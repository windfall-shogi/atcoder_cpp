#include <iostream>
#include <cmath>

int main()
{
    int a, b;
    std::cin >> a >> b;
    const auto shift = std::floor(std::log10(b) + 1);
    const auto x = std::pow(10, shift) * a + b;
    const auto y = static_cast<int>(std::sqrt(x));

    std::cout << (x == y * y ? "Yes" : "No") << std::endl;
    return 0;
}
