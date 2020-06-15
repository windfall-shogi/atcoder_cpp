#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    if ((s.front() == s.back()) == (s.size() % 2 == 1))
    {
        std::cout << "Second";
    }
    else
    {
        std::cout << "First";
    }
    std::cout << std::endl;

    return 0;
}
