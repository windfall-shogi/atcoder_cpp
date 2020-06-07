#include <iostream>
#include <unordered_set>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    std::unordered_set<int> set{a, b, c};
    std::cout << set.size() << std::endl;
    return 0;
}
