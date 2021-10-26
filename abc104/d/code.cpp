#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;
    std::vector<int64_t> dp(4), previous(4);

    constexpr int64_t MOD = 1000000007;

    for (int i = 0; i < s.size(); ++i)
    {
        if (i == 0)
        {
            if (s[i] == '?')
            {
                dp[0] = 3;
            }
            else
            {
                dp[0] = 1;
            }
            if (s[i] == 'A' || s[i] == '?')
            {
                dp[1] = 1;
            }
        }
        else
        {
            for (int j = 0; j <= 3; ++j)
            {
                if (s[i] == '?')
                {
                    dp[j] = 3 * previous[j] % MOD;
                }
                else
                {
                    dp[j] = previous[j];
                }
            }
            if (s[i] == 'A' || s[i] == '?')
            {
                dp[1] += previous[0];
                dp[1] %= MOD;
            }
            if (s[i] == 'B' || s[i] == '?')
            {
                dp[2] += previous[1];
                dp[2] %= MOD;
            }
            if (s[i] == 'C' || s[i] == '?')
            {
                dp[3] += previous[2];
                dp[3] %= MOD;
            }
        }
        dp.swap(previous);
    }

    std::cout << previous[3] << std::endl;

    return 0;
}
