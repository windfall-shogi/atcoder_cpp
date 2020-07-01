#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;

    const size_t first = s.find_first_of('A');
    const size_t last = s.find_last_of('Z');
    std::cout << last - first + 1 << std::endl;

    return 0;
}
