#include <iostream>
#include <vector>

int64_t table[50][5000];

int main()
{
    int n, a;
    std::cin >> n >> a;

    std::vector<int> values;
    values.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        values.push_back(tmp - a);
    }

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            table[i][2500] = 1;
            // value[i]が0の場合がある
            table[i][values[i] + 2500] += 1;
        }
        else
        {
            for (int j = 0; j < 5000; ++j)
            {
                if (j - values[i] < 0 || j - values[i] >= 5000)
                {
                    table[i][j] = table[i - 1][j];
                }
                else
                {
                    table[i][j] = table[i - 1][j] + table[i - 1][j - values[i]];
                }
            }
        }
    }

    std::cout << table[n - 1][2500] - 1 << std::endl;
    return 0;
}
