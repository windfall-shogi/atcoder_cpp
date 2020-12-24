#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string sp, t;
    std::cin >> sp >> t;

    if (t.size() > sp.size())
    {
        std::cout << "UNRESTORABLE" << std::endl;
        return 0;
    }

    std::vector<std::string> candidates;
    for (size_t i = 0; i <= sp.size() - t.size(); ++i)
    {
        std::string s = sp;
        bool flag = true;
        for (size_t j = 0; j < s.size(); ++j)
        {
            if (j < i)
            {
                if (s[j] == '?')
                {
                    s[j] = 'a';
                }
            }
            else if (j < i + t.size())
            {
                if (s[j] == '?')
                {
                    s[j] = t[j - i];
                }
                else
                {
                    if (s[j] != t[j - i])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            else
            {
                if (s[j] == '?')
                {
                    s[j] = 'a';
                }
            }

            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            candidates.emplace_back(std::move(s));
        }
    }
    if (candidates.empty())
    {
        std::cout << "UNRESTORABLE" << std::endl;
    }
    else
    {
        std::sort(candidates.begin(), candidates.end());
        std::cout << candidates.front() << std::endl;
    }

    return 0;
}
