#include <iostream>

int main()
{
    int n, a;
    std::cin >> n >> a;
    n %= 500;
    std::cout << (n <= a ? "Yes" : "No") << std::endl;
    return 0;
}
