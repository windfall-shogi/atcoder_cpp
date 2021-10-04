#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;

    size_t ans = s.size();
    for (size_t i = 1; i < s.size(); ++i)
    {
        if (s[i] != s[i - 1])
        {
            ans = std::min(ans, std::max(i, s.size() - i));
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
