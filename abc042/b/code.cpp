#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    int n, l;
    std::cin >> n >> l;

    std::vector<std::string> str;
    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        str.emplace_back(std::move(tmp));
    }
    std::sort(str.begin(), str.end());

    for (const auto &s : str)
    {
        std::cout << s;
    }
    std::cout << std::endl;

    return 0;
}
