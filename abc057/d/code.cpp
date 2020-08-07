#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int64_t table[51][51];

// パスカルの三角形で二項係数を計算
void InitializeTable(const int n)
{
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
            {
                table[i][j] = 1;
            }
            else
            {
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
            }
        }
    }
}

int main()
{
    int n, a, b;
    std::cin >> n >> a >> b;

    InitializeTable(n);

    std::vector<int64_t> arr(n);
    for (int i = 0; i < n; ++i)
    {
        int64_t v;
        std::cin >> v;
        arr[i] = v;
    }
    // 降順でソート
    std::sort(arr.begin(), arr.end(), std::greater<int64_t>());

    const int m = std::distance(arr.begin(), std::find(arr.begin(), arr.end(), arr[a - 1]));
    const int count = std::count(arr.begin(), arr.end(), arr[a - 1]);
    int64_t combination = 0;
    if (m != 0)
    {
        const int k = a - m;
        combination = table[count][k];
    }
    else
    {
        for (int k = a; k <= b; ++k)
        {
            combination += table[count][k];
        }
    }

    const int64_t sum = std::accumulate(arr.begin(), arr.begin() + a, static_cast<int64_t>(0));
    const double ave = static_cast<double>(sum) / a;

    std::cout.precision(20);
    std::cout << std::fixed << ave << std::endl;
    std::cout << combination << std::endl;

    return 0;
}
