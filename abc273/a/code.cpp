#include <iostream>

int f(const int i)
{
    if (i == 0)
    {
        return 1;
    }
    else
    {
        return i * f(i - 1);
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << f(n) << std::endl;
    return 0;
}
