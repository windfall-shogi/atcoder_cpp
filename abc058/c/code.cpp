#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> min_count(26, 999);
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;

        std::vector<int> count(26);
        for (const char c : s)
        {
            ++count[c - 'a'];
        }

        std::transform(min_count.begin(), min_count.end(),
                       count.begin(), min_count.begin(),
                       [](const int x, const int y) {
                           return std::min(x, y);
                       });
    }

    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < min_count[i]; ++j)
        {
            std::cout << static_cast<char>('a' + i);
        }
    }
    std::cout << std::endl;
    return 0;
}
