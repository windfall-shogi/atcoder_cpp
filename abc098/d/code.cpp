#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    constexpr int DIGITS = 21;
    std::vector<std::vector<int>> counter(DIGITS);
    std::vector<int> buffer(n + 1);
    buffer[n] = 0;
    for (int d = 0; d < DIGITS; ++d)
    {
        std::transform(as.begin(), as.end(), buffer.begin(), [d](const int x)
                       { return (x >> d) & 0x1; });

        counter[d].resize(n + 1);
        std::partial_sum(buffer.rbegin(), buffer.rend(), counter[d].rbegin());
    }

    int64_t ans = n;
    for (int l = 0; l < n - 1; ++l)
    {
        for (int r = l + 1; r < n; ++r)
        {
            bool flag = true;
            for (int d = DIGITS - 1; d >= 0; --d)
            {
                const int bits = counter[d][r + 1] - counter[d][l];
                if (bits >= 2)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }

            int carry = (counter[0][r + 1] - counter[0][l]) / 2;
            for (int d = 1; d < DIGITS; ++d)
            {
                int bits = counter[d][r + 1] - counter[d][l];

                int xor_result = bits % 2;
                int add_result = (bits + carry) % 2;

                if (add_result != xor_result)
                {
                    flag = false;
                    break;
                }

                carry = (bits + carry) / 2;
            }
            if (flag)
            {
                ++ans;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
