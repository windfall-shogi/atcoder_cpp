#include <iostream>
#include <vector>
#include <string>
#include <numeric>

bool solve(const int m, const int64_t K, const std::vector<int64_t> &B, const std::vector<int64_t> &C)
{
    if (m == 0)
    {
        return true;
    }
    else if (m == 1)
    {
        return C.size() >= 2;
    }

    const int n = m / 2;
    for (int i = 0; i + m - 1 < static_cast<int>(B.size()); ++i)
    {
        const int64_t tmp1 = B[i + n] * n - (C[i + n] - C[i]);
        const int64_t tmp2 = (C[i + m] - C[i + n]) - B[i + n] * (m - n);
        if (tmp1 + tmp2 <= K)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::string S;
    std::cin >> S;
    int64_t K;
    std::cin >> K;

    std::vector<int64_t> B;
    int count = 0;
    for (int i = 0; i < static_cast<int>(S.size()); ++i)
    {
        if (S[i] == 'Y')
        {
            B.emplace_back(i - count);
            ++count;
        }
    }

    std::vector<int64_t> C(B.size() + 1);
    std::partial_sum(B.begin(), B.end(), C.begin() + 1);

    int l = 0, r = static_cast<int>(S.size()) + 1;
    while (l + 1 != r)
    {
        const int m = (l + r) / 2;
        if (solve(m, K, B, C))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }

    std::cout << l << std::endl;

    return 0;
}
