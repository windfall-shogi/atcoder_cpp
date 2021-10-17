#include <iostream>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    const auto flag = std::abs(a - c) <= d || (std::abs(a - b) <= d && std::abs(b - c) <= d);
    std::cout << (flag ? "Yes" : "No") << std::endl;
    return 0;
}
