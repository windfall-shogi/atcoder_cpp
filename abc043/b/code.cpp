#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    std::vector<char> buffer;
    buffer.reserve(10);
    for (const char &s : str)
    {
        if (s == 'B')
        {
            if (buffer.empty())
            {
                continue;
            }
            buffer.pop_back();
        }
        else
        {
            buffer.push_back(s);
        }
    }

    for (const char &s : buffer)
    {
        std::cout << s;
    }
    std::cout << std::endl;

    return 0;
}
