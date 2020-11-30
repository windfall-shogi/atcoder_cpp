#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    if (s[0] == '9' || s[1] == '9')
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    return 0;
}
