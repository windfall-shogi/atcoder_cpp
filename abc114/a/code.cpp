#include <iostream>

int main()
{
    int x;
    std::cin >> x;
    std::cout << ((x == 7 || x == 5 || x == 3) ? "YES" : "NO") << std::endl;
    return 0;
}
