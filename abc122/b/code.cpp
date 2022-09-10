#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
    const std::unordered_set<char> set{'A', 'T', 'C', 'G'};

    std::string s;
    std::cin >> s;
    int64_t ans = 0;
    int64_t l = 0;
    while (l < s.size())
    {
        bool end_flag = true;
        for (int64_t r = l; r < s.size(); ++r)
        {
            const auto c = s[r];
            if (set.count(c) == 0)
            {
                ans = std::max(ans, r - l);
                end_flag = false;
                l = r + 1;
                break;
            }
        }
        if (end_flag)
        {
            ans = std::max<int64_t>(ans, s.size() - l);
            break;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
