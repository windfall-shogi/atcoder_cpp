#include <iostream>
#include <string>

int main()
{
    std::string a, b;
    std::cin >> a;
    std::cin >> b;

    if (a.size() == b.size())
    {
        bool flag = true;
        for (size_t i = 0; i < a.size(); ++i)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            else if (a[i] > b[i])
            {
                std::cout << "GREATER";
            }
            else
            {
                std::cout << "LESS";
            }
            flag = false;
            break;
        }
        if (flag)
        {
            std::cout << "EQUAL";
        }
    }
    else if (a.size() > b.size())
    {
        std::cout << "GREATER";
    }
    else
    {
        std::cout << "LESS";
    }
    std::cout << std::endl;

    return 0;
}
