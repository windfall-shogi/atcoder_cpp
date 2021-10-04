#include <iostream>
#include <string>
#include <cctype>

bool check(const std::string &s, const int a, const int b)
{
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (i == a)
        {
            if (s[i] != '-')
            {
                return false;
            }
        }
        else
        {
            if (std::isdigit(s[i]) == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::string s;
    std::cin >> s;

    std::cout << (check(s, a, b) ? "Yes" : "No") << std::endl;
    return 0;
}
