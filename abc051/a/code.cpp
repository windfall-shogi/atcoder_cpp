#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    for (const char c : s)
    {
        if (c == ',')
        {
            std::cout << ' ';
        }
        else
        {
            std::cout << c;
        }
    }
    std::cout << std::endl;

    return 0;
}
