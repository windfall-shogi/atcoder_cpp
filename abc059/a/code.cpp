#include <iostream>
#include <locale>
#include <string>

int main()
{
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    const auto l = std::locale();
    std::cout << std::toupper(s1[0], l) << std::toupper(s2[0], l)
              << std::toupper(s3[0], l) << std::endl;
    return 0;
}
