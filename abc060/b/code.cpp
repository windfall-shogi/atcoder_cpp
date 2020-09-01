#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    bool flag = false;
    for (int i = 1; i <= b; ++i)
    {
        if (a * i % b == c)
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    std::cout << std::endl;
    return 0;
}
