#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    for (const auto c : s)
    {
        std::cout << (c == '1' ? '9' : '1');
    }
    std::cout << std::endl;
    return 0;
}
