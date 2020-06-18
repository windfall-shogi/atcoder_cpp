#include <iostream>
#include <unordered_map>

constexpr int32_t M = 1000000007;

int32_t Compute(const int n, const std::unordered_map<int, int> &a)
{
    if (n % 2 == 1)
    {
        try
        {
            if (a.at(0) != 1)
            {
                return 0;
            }
            for (int i = 2; i <= n - 1; i += 2)
            {
                if (a.at(i) != 2)
                {
                    return 0;
                }
            }
        }
        catch (const std::exception &e)
        {
            return 0;
        }

        int32_t sum = 1;
        for (int i = 0; i < (n - 1) / 2; ++i)
        {
            sum = sum * 2 % M;
        }
        return sum;
    }
    else
    {
        try
        {
            for (int i = 1; i <= n - 1; i += 2)
            {
                if (a.at(i) != 2)
                {
                    return 0;
                }
            }
        }
        catch (const std::exception &e)
        {
            return 0;
        }

        int32_t sum = 1;
        for (int i = 0; i < n / 2; ++i)
        {
            sum = sum * 2 % M;
        }
        return sum;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::unordered_map<int, int> a;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        ++a[tmp];
    }

    std::cout << Compute(n, a) << std::endl;
    return 0;
}
