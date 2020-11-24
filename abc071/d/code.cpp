#include <iostream>
#include <string>
#include <vector>

constexpr int32_t MOD = 1000000007;

int main()
{
    int n;
    std::cin >> n;
    std::string s1, s2;
    std::cin >> s1;
    std::cin >> s2;

    // 縦ならtrue、横ならfalse
    std::vector<bool> pattern;
    for (int i = 0; i < n; ++i)
    {
        if (s1[i] == s2[i])
        {
            pattern.push_back(true);
        }
        else
        {
            pattern.push_back(false);
            ++i;
        }
    }

    int64_t count = pattern[0] ? 3 : 6;
    for (size_t i = 1; i < pattern.size(); ++i)
    {
        if (pattern[i])
        {
            if (pattern[i - 1])
            {
                count *= 2;
            }
            else
            {
                // 一通りしかない
            }
        }
        else
        {
            if (pattern[i - 1])
            {
                count *= 2;
            }
            else
            {
                count *= 3;
            }
        }
        count %= MOD;
    }

    std::cout << count << std::endl;
    return 0;
}
