#include <iostream>

double compute(const int64_t x)
{
    int s = 0;
    int64_t tmp = x;
    while (tmp > 0)
    {
        s += tmp % 10;
        tmp /= 10;
    }

    return static_cast<double>(x) / s;
}

int64_t solve(const int64_t x)
{
    int64_t scale = 10;
    int64_t candidate = x;
    double current_value = compute(x);
    while (true)
    {
        const int64_t y = scale * (x / scale + 1) - 1;
        const double value = compute(y);
        if (value < current_value)
        {
            candidate = y;
            current_value = value;
        }

        if (scale > x)
        {
            break;
        }
        scale *= 10;
    }

    return candidate;
}

int main()
{
    int k;
    std::cin >> k;

    int64_t sunuke = 1;
    for (int i = 0; i < k; ++i)
    {
        std::cout << sunuke << std::endl;
        if (sunuke < 9)
        {
            ++sunuke;
        }
        else
        {
            sunuke = solve(sunuke + 1);
        }
    }

    return 0;
}
