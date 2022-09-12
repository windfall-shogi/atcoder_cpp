#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;

    int64_t ans1 = 0, ans2 = 0;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (i % 2 == 0)
        {
            if (s[i] == '0')
            {
                ++ans1;
            }
            if (s[i] == '1')
            {
                ++ans2;
            }
        }
        else
        {
            if (s[i] == '1')
            {
                ++ans1;
            }
            if (s[i] == '0')
            {
                ++ans2;
            }
        }
    }

    std::cout << std::min(ans1, ans2) << std::endl;
    return 0;
}
