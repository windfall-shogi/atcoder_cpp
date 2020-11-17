#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;
    std::vector<bool> flag(26);
    for (const auto c : s)
    {
        flag[c - 'a'] = true;
    }

    std::string result = "None";
    for (int i = 0; i < 26; ++i)
    {
        if (!flag[i])
        {
            result = i + 'a';
            break;
        }
    }

    std::cout << result << std::endl;
    return 0;
}
