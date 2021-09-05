#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;

    const auto n = std::count(s.begin(), s.end(), '1');
    std::cout << n << std::endl;

    return 0;
}
