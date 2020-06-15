#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    bool flag = true;
    for (std::string::const_reverse_iterator it = s.rbegin(); it != s.rend();)
    {
        if (*it == 'm')
        {
            ++it;
            if (!(std::distance(it, s.crend()) >= 4 && *it++ == 'a' && *it++ == 'e' && *it++ == 'r' && *it++ == 'd'))
            {
                flag = false;
                break;
            }
        }
        else if (*it == 'e')
        {
            ++it;
            if (!(std::distance(it, s.crend()) >= 4 && *it++ == 's' && *it++ == 'a' && *it++ == 'r' && *it++ == 'e'))
            {
                flag = false;
                break;
            }
        }
        else if (*it == 'r')
        {
            ++it;
            if (!(it != s.rend() && *it++ == 'e'))
            {
                flag = false;
                break;
            }

            if (*it == 'm')
            {
                ++it;
                if (!(std::distance(it, s.crend()) >= 4 && *it++ == 'a' && *it++ == 'e' && *it++ == 'r' && *it++ == 'd'))
                {
                    flag = false;
                    break;
                }
            }
            else if (*it == 's')
            {
                ++it;
                if (!(std::distance(it, s.crend()) >= 3 && *it++ == 'a' && *it++ == 'r' && *it++ == 'e'))
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    std::cout << std::endl;

    return 0;
}
