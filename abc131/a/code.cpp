#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    bool good = true;
    for (int i = 1; i < 4; ++i)
    {
        if (s[i] == s[i - 1])
        {
            good = false;
            break;
        }
    }
    std::cout << (good ? "Good" : "Bad") << std::endl;
    return 0;
}
