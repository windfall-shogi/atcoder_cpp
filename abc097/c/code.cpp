#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;

    std::set<std::string> set;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != c)
            {
                continue;
            }
            for (int len = 1; len <= std::min<size_t>(5, s.size() - i + 1); ++len)
            {
                set.emplace(s.substr(i, len));
            }
        }

        if (set.size() >= k)
        {
            break;
        }
    }

    int count = 0;
    for (const auto &s2 : set)
    {
        ++count;
        if (count == k)
        {
            std::cout << s2 << std::endl;
            break;
        }
    }

    return 0;
}
