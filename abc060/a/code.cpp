#include <iostream>
#include <string>

int main()
{
    std::string a, b, c;
    std::cin >> a >> b >> c;
    if (a.back() == b.front() && b.back() == c.front())
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    std::cout << std::endl;
    return 0;
}
