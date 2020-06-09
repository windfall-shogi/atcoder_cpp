#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    bool flag = (a + b == c) || (b + c == a) || (c + a == b);
    if (flag)
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }
    std::cout << std::endl;
    return 0;
}
