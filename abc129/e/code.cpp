#include <iostream>
#include <string>
#include <vector>

int main()
{
    constexpr int64_t MOD = 1000000007;
    std::string s;
    std::cin >> s;

    std::vector<int64_t> current(2), previous(2);
    current[1] = 2;
    current[0] = 1;
    for (size_t i = 1; i < s.size(); ++i)
    {
        previous.swap(current);

        if (s[i] == '1')
        {
            current[1] = 2 * previous[1] % MOD;
            current[0] = (previous[1] + 3 * previous[0]) % MOD;
        }
        else
        {
            current[1] = previous[1];
            current[0] = 3 * previous[0] % MOD;
        }
    }
    std::cout << (current[0] + current[1]) % MOD << std::endl;

    return 0;
}
