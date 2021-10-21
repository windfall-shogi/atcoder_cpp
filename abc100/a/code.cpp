#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << ((a >= 9 || b >= 9) ? ":(" : "Yay!") << std::endl;
    return 0;
}
