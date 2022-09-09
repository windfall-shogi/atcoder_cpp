#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::string s;
    std::cin >> s;
    int r = 0, b = 0;
    for (const auto c : s)
    {
        if (c == '0')
        {
            ++r;
        }
        else
        {
            ++b;
        }
    }
    std::cout << 2 * std::min(r, b) << std::endl;
    return 0;
}
