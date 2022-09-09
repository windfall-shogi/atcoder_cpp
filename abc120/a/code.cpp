#include <iostream>
#include <utility>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::min(c, b / a) << std::endl;
    return 0;
}
