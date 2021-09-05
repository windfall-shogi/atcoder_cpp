#include <iostream>

int main()
{
    int n;
    int a = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        a |= tmp;
    }

    int count = 0;
    while ((a & 1) == 0)
    {
        ++count;
        a >>= 1;
    }

    std::cout << count << std::endl;
    return 0;
}
