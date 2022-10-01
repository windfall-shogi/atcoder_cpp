#include <iostream>
#include <vector>

int dp[101][10010];

enum Side
{
    A = 1,
    B = 2
};

int main()
{
    int n, s;
    std::cin >> n >> s;
    std::vector<int> as(n), bs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i] >> bs[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            dp[i][as[i]] = A;
            dp[i][bs[i]] = B;
        }
        else
        {
            for (int j = 0; j <= 10000; ++j)
            {
                if (dp[i - 1][j] != 0)
                {
                    dp[i][j + as[i]] = A;
                    dp[i][j + bs[i]] = B;
                }
            }
        }
    }

    if (dp[n - 1][s] != 0)
    {
        std::cout << "Yes" << std::endl;

        std::vector<char> buffer(n);
        for (int i = n - 1; i >= 0; --i)
        {
            if (dp[i][s] == A)
            {
                buffer[i] = 'H';
                s -= as[i];
            }
            else
            {
                buffer[i] = 'T';
                s -= bs[i];
            }
        }
        for (const auto c : buffer)
        {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}
