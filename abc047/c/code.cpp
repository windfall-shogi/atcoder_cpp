#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    char current = str[0];
    int count = 0;
    for (const char c : str)
    {
        if (c != current)
        {
            ++count;
            current = c;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
