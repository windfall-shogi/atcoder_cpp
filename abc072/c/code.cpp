#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    int table[100000 + 1];
    std::fill(std::begin(table), std::end(table), 0);

    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;

        ++table[a - 1];
        ++table[a];
        ++table[a + 1];
    }

    const auto x = *std::max_element(std::begin(table), std::end(table));
    std::cout << x << std::endl;
    return 0;
}
