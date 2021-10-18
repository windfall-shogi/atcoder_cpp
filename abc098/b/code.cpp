#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int ans = 0;
    for (auto it = ++s.begin(); it != --s.end(); ++it)
    {
        std::unordered_set<char> s1(s.begin(), it), s2(it, s.end());
        int count = 0;
        for (const auto c : s1)
        {
            const auto it2 = s2.find(c);
            if (it2 != s2.end())
            {
                ++count;
            }
        }

        if (count > ans)
        {
            ans = count;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
