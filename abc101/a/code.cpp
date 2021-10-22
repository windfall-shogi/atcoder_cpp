#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    int ans = 0;
    for (const char c : s)
    {
        if (c == '+')
        {
            ++ans;
        }
        else
        {
            --ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
