#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    if (s.front() == s.back())
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    return 0;
}
