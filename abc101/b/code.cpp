#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int tmp = n;
    int s = 0;
    while (tmp != 0)
    {
        s += tmp % 10;
        tmp /= 10;
    }

    std::cout << (n % s == 0 ? "Yes" : "No") << std::endl;

    return 0;
}
