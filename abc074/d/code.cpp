#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using Matrix = std::vector<std::vector<int64_t>>;

Matrix WarshallFloyd(const Matrix &a)
{
    const auto n = a.size();
    Matrix d(n);
    for (size_t i = 0; i < n; ++i)
    {
        d[i].resize(n);
        std::copy(a[i].begin(), a[i].end(), d[i].begin());
    }

    for (size_t k = 0; k < n; ++k)
    {
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    return d;
}

int64_t Check(const Matrix &a, const Matrix &b)
{
    int64_t total = 0;
    const auto n = a.size();
    for (size_t i = 0; i < n - 1; ++i)
    {
        for (size_t j = i + 1; j < n; ++j)
        {
            if (a[i][j] > b[i][j])
            {
                return -1;
            }
            int64_t tmp = std::numeric_limits<int64_t>::max();
            for (size_t k = 0; k < n; ++k)
            {
                if (i == k || j == k)
                {
                    continue;
                }
                tmp = std::min(tmp, b[i][k] + b[k][j]);
            }
            if (a[i][j] < tmp)
            {
                total += a[i][j];
            }
        }
    }

    return total;
}

int main()
{
    int n;
    std::cin >> n;
    Matrix a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i].resize(n);
        for (int j = 0; j < n; ++j)
        {
            int tmp;
            std::cin >> tmp;
            a[i][j] = tmp;
        }
    }

    const auto b = WarshallFloyd(a);
    const auto ans = Check(a, b);  
    std::cout << ans << std::endl;

    return 0;
}
