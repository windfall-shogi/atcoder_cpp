#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;
    const auto r = static_cast<int>(std::sqrt(n));
    std::cout << r * r << std::endl;
    return 0;
}
