#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string str;
    std::cin >> str;

    int p = -1, q = -1;
    for (int i = 0; i < str.size() - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            p = i + 1;
            q = i + 2;
            break;
        }
        else if (i < str.size() - 2 && str[i] == str[i + 2])
        {
            p = i + 1;
            q = i + 3;
            break;
        }
    }

    std::cout << p << ' ' << q << std::endl;
    return 0;
}
