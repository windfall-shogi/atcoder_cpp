#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    const int x = n * 800;
    const int y = (n / 15) * 200;
    std::cout << x - y << std::endl;
    return 0;
}
