#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;
    int ans = 10000;
    for (int i = 0; i < s.size() - 2; ++i)
    {
        const int num = std::stoi(s.substr(i, 3));
        ans = std::min(ans, std::abs(num - 753));
    }

    std::cout << ans << std::endl;

    return 0;
}
