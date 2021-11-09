#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    std::cout << (n + 111 - 1) / 111 * 111 << std::endl;
    return 0;
}
