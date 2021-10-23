#include <iostream>

int main()
{
    int64_t n;
    std::cin >> n;
    std::cout << (n % 2 == 0 ? n : 2 * n) << std::endl;
    return 0;
}
