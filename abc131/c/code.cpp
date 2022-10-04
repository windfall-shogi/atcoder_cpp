#include <iostream>
#include <numeric>

int main()
{
    int64_t a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int64_t ans = b - a + 1;

    const int64_t q1_c = (a + c - 1) / c;
    const int64_t q2_c = b / c;
    if (q1_c <= q2_c)
    {
        ans -= q2_c - q1_c + 1;
    }
    const int64_t q1_d = (a + d - 1) / d;
    const int64_t q2_d = b / d;
    if (q1_d <= q2_d)
    {
        ans -= q2_d - q1_d + 1;
    }
    const int64_t e = std::lcm(c, d);
    const int64_t q1_e = (a + e - 1) / e;
    const int64_t q2_e = b / e;
    if (q1_e <= q2_e)
    {
        ans += q2_e - q1_e + 1;
    }

    std::cout << ans << std::endl;
    return 0;
}
