#include <iostream>
#include <algorithm>

int main()
{
    int a, b;
    std::cin >> a >> b;

    constexpr int size = 100;
    char table[size][size];
    for (int i = 0; i < size / 2; ++i)
    {
        std::fill(std::begin(table[i]), std::end(table[i]), '#');
        std::fill(std::begin(table[i + size / 2]), std::end(table[i + size / 2]), '.');
    }
    --a;
    --b;

    const int row_a = (a + size / 2 - 1) / (size / 2);
    for (int i = 0; i < row_a; ++i)
    {
        const int col_a = std::min(a, size / 2);
        for (int j = 0; j < col_a; ++j)
        {
            table[i * 2][j * 2] = '.';
            --a;
        }
    }

    const int row_b = (b + size / 2 - 1) / (size / 2);
    for (int i = 0; i < row_b; ++i)
    {
        const int col_b = std::min(b, size / 2);
        for (int j = 0; j < col_b; ++j)
        {
            table[size - 1 - 2 * i][j * 2] = '#';
            --b;
        }
    }

    std::cout << size << ' ' << size << std::endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << table[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
