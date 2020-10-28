#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int k = 1;
    while (2 * k <= n)
    {
        k *= 2;
    }

    std::cout << k << std::endl;

    return 0;
}
