#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << s.front() << s.size() - 2 << s.back() << std::endl;
    return 0;
}
