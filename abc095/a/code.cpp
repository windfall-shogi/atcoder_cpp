#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    int count = 0;
    for (const char c : s)
    {
        if (c == 'o')
        {
            ++count;
        }
    }
    std::cout << 700 + count * 100 << std::endl;
    return 0;
}
