#include <iostream>
#include <unordered_set>

int main()
{
    const std::unordered_set<int> g1{1, 3, 5, 7, 8, 10, 12}, g2{4, 6, 9, 11}, g3{2};
    int x, y;
    std::cin >> x >> y;

    bool same = false;
    if (g1.find(x) != g1.end())
    {
        same = g1.find(y) != g1.end();
    }
    else if (g2.find(x) != g2.end())
    {
        same = g2.find(y) != g2.end();
    }
    else
    {
        same = false;
    }

    if (same)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    return 0;
}
