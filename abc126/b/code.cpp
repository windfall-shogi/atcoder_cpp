#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    const int a = (s[0] - '0') * 10 + s[1] - '0';
    const int b = (s[2] - '0') * 10 + s[3] - '0';

    const bool flag_a = a >= 1 && a <= 12;
    const bool flag_b = b >= 1 && b <= 12;
    if (flag_a && flag_b)
    {
        std::cout << "AMBIGUOUS" << std::endl;
    }
    else if (flag_a)
    {
        std::cout << "MMYY" << std::endl;
    }
    else if (flag_b)
    {
        std::cout << "YYMM" << std::endl;
    }
    else
    {
        std::cout << "NA" << std::endl;
    }
    return 0;
}
