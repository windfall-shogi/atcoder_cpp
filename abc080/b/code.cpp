#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    const int n = std::stoi(s);

    int k = 0;
    for (const auto c : s)
    {
        k += c - '0';
    }

    if (n % k == 0)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}
