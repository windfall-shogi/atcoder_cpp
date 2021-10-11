#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    int n, m;
    std::cin >> n;
    std::unordered_map<std::string, int> blues;
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        ++blues[s];
    }
    std::cin >> m;
    std::unordered_map<std::string, int> reds;
    for (int i = 0; i < m; ++i)
    {
        std::string t;
        std::cin >> t;
        ++reds[t];
    }

    int ans = 0;
    for (const auto &e : blues)
    {
        const auto it = reds.find(e.first);
        if (it == reds.end())
        {
            ans = std::max(ans, e.second);
        }
        else
        {
            ans = std::max(ans, e.second - it->second);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
