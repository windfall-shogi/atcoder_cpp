#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    std::cout << (s == "abc" ? "Yes" : "No") << std::endl;
    return 0;
}
