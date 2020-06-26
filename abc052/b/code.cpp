#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int x = 0, max_x = 0;
    for (const char c : s)
    {
        if (c == 'I')
        {
            ++x;
        }
        else
        {
            --x;
        }
        max_x = std::max(x, max_x);
    }

    std::cout << max_x << std::endl;
    return 0;
}
