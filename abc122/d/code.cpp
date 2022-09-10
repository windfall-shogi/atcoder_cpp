#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>

int main()
{
    constexpr int64_t MOD = 1000000007;
    int64_t n;
    std::cin >> n;
    /*
    AGC
    AGAC
    AGGC
    AGTC
    ACG
    GAC
    ACGC
    ATGC
    */
    const std::unordered_set<std::string> bad3{"AGC", "ACG", "GAC"};
    const std::unordered_set<std::string> bad4{"AGAC", "AGGC", "AGTC", "ACGC", "ATGC"};

    if (n == 3)
    {
        std::cout << 61 << std::endl;
        return 0;
    }

    const std::string s = "ACGT";
    std::string buf("AAA");
    std::unordered_map<std::string, int64_t> current, next;
    for (const auto c1 : s)
    {
        buf[0] = c1;
        for (const auto c2 : s)
        {
            buf[1] = c2;
            for (const auto c3 : s)
            {
                buf[2] = c3;
                if (bad3.count(buf) == 0)
                {
                    current[buf] = 1;
                }
            }
        }
    }

    for (int64_t i = 4; i <= n; ++i)
    {
        next.clear();
        for (const auto &e : current)
        {
            for (const auto c : s)
            {
                const auto tmp1 = e.first.substr(1, 2) + c;
                if (bad3.count(tmp1) != 0)
                {
                    continue;
                }
                const auto tmp2 = e.first + c;
                if (bad4.count(tmp2) != 0)
                {
                    continue;
                }

                const auto key = tmp2.substr(1, 3);
                next[key] += e.second;
                next[key] %= MOD;
            }
        }
        current.swap(next);
    }

    int64_t ans = 0;
    for (const auto &e : current)
    {
        ans += e.second;
        ans %= MOD;
    }
    std::cout << ans << std::endl;

    return 0;
}
