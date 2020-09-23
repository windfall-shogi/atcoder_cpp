#include <iostream>
#include <array>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    bool varied = true;
    std::array<bool, 26> count = {false};
    for (const auto c : s)
    {
        if (count[c - 'a'])
        {
            varied = false;
            break;
        }
        count[c - 'a'] = true;
    }

    if (varied)
    {
        std::cout << "yes";
    }
    else
    {
        std::cout << "no";
    }
    std::cout << std::endl;
    return 0;
}
