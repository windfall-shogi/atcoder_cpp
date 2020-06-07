#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    int64_t t, a;
    std::cin >> t >> a;
    for (int i = 1; i < n; ++i)
    {
        int64_t tmp_t, tmp_a;
        std::cin >> tmp_t >> tmp_a;

        if (tmp_t == 1 && tmp_a == 1)
        {
            // 自明
            t = a = std::max(t, a);
            continue;
        }

        const auto current = static_cast<double>(t) / a, target = static_cast<double>(tmp_t) / tmp_a;
        if (target > current)
        {
            // tがより増加する

            // aはtmp_aの倍数にならなければならない
            a = (a + tmp_a - 1) / tmp_a * tmp_a;
            // aは倍数になったのであまりはない
            t = a / tmp_a * tmp_t;
        }
        else
        {
            // aがより増加する

            t = (t + tmp_t - 1) / tmp_t * tmp_t;
            a = t / tmp_t * tmp_a;
        }
    }

    std::cout << t + a << std::endl;
    return 0;
}
