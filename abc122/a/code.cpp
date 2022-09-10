#include <iostream>
#include <unordered_map>

int main()
{
    const std::unordered_map<char, char> table{{'A', 'T'}, {'T', 'A'}, {'C', 'G'}, {'G', 'C'}};
    char c;
    std::cin >> c;
    std::cout << table.at(c) << std::endl;
    return 0;
}
