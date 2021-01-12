#include <iostream>
#include <string>

int main()
{
    std::string s[2];
    std::cin >> s[0] >> s[1];

    bool flag = true;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (s[i][j] != s[1 - i][2 - j])
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
