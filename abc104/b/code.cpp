#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string s;
    std::cin >> s;
    std::regex re("^A[a-z]+C[a-z]*[a-z]$");
    std::cout << (std::regex_match(s, re) ? "AC" : "WA") << std::endl;
    return 0;
}
