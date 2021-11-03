#include <iostream>
#include <string>

int main()
{
    std::string s;
    int k;
    std::cin >> s >> k;

    char c;
    for (int i = 0; i < k; ++i)
    {
        c = s[i];
        if (s[i] != '1')
        {
            break;
        }
    }

    std::cout << c << std::endl;
}
