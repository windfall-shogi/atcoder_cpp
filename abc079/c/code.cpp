#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    for (int v = 0; v < (1 << 3); ++v)
    {
        int r = s[0] - '0';
        for (int i = 0; i < 3; ++i)
        {
            if ((v & (1 << i)) == 0)
            {
                r = r + (s[i + 1] - '0');
            }
            else
            {
                r = r - (s[i + 1] - '0');
            }
        }
        if (r == 7)
        {
            for (int i = 0; i < 3; ++i)
            {
                std::cout << s[i];
                if ((v & (1 << i)) == 0)
                {
                    std::cout << '+';
                }
                else
                {
                    std::cout << '-';
                }
            }
            std::cout << s[3] << "=7" << std::endl;

            break;
        }
    }

    return 0;
}
