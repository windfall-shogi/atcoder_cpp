#include <iostream>
#include <string>
#include <array>
#include <algorithm>

int main()
{
    std::string str;
    std::cin >> str;
    std::array<int, 26> counter = {0};
    for (const char c : str)
    {
        ++counter[c - 'a'];
    }

    const auto it = std::find_if(counter.begin(), counter.end(), [](const int v) { return v % 2; });
    if (it != counter.end())
    {
        std::cout << "No";
    }
    else
    {
        std::cout << "Yes";
    }
    std::cout << std::endl;

    return 0;
}
