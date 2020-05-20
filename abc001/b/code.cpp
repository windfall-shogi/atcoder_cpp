#include <iostream>

int main()
{
    int m;
    std::cin >> m;
    if (m < 100)
    {
        std::cout << "00";
    }
    else if (m >= 100 && m <= 5000)
    {
        m /= 100;
        if (m < 10)
        {
            std::cout << '0';
        }
        std::cout << m;
    }
    else if (m >= 6000 && m <= 30000)
    {
        m /= 1000;
        m += 50;
        std::cout << m;
    }
    else if (m >= 35000 && m <= 70000)
    {
        m /= 1000;
        m = (m - 30) / 5 + 80;
        std::cout << m;
    }
    else
    {
        std::cout << "89";
    }
    std::cout << std::endl;

    return 0;
}
