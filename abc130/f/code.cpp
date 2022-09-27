#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

constexpr double inf = 1e20;

struct Range
{
    double min_fixed, max_fixed;
    double min_inc, max_inc;
    double min_dec, max_dec;
    bool is_horizontal;
    Range(const bool d) : min_fixed(inf), max_fixed(-inf), min_inc(inf), max_inc(-inf),
                          min_dec(inf), max_dec(-inf), is_horizontal(d) {}
    void add(const double v, const char d)
    {
        if (is_horizontal)
        {
            if (d == 'R')
            {
                max_inc = std::max(v, max_inc);
                min_inc = std::min(v, min_inc);
            }
            else if (d == 'L')
            {
                max_dec = std::max(v, max_dec);
                min_dec = std::min(v, min_dec);
            }
            else
            {
                max_fixed = std::max(v, max_fixed);
                min_fixed = std::min(v, min_fixed);
            }
        }
        else
        {
            if (d == 'U')
            {
                max_inc = std::max(v, max_inc);
                min_inc = std::min(v, min_inc);
            }
            else if (d == 'D')
            {
                max_dec = std::max(v, max_dec);
                min_dec = std::min(v, min_dec);
            }
            else
            {
                max_fixed = std::max(v, max_fixed);
                min_fixed = std::min(v, min_fixed);
            }
        }
    }

    void get_events(std::vector<double> &cp) const
    {
        if (min_inc != inf && min_inc < min_fixed)
        {
            cp.emplace_back(min_fixed - min_inc);
        }
        if (max_inc != -inf && max_inc < max_fixed)
        {
            cp.emplace_back(max_fixed - max_inc);
        }

        if (min_dec != inf && min_dec > min_fixed)
        {
            cp.emplace_back(min_dec - min_fixed);
        }
        if (max_dec != -inf && max_dec > max_fixed)
        {
            cp.emplace_back(max_dec - max_fixed);
        }

        if (min_dec != inf && min_inc != inf && min_dec > min_inc)
        {
            cp.emplace_back((min_dec - min_inc) * 0.5);
        }
        if (max_dec != -inf && max_inc != -inf && max_dec > max_inc)
        {
            cp.emplace_back((max_dec - max_inc) * 0.5);
        }
    }

    double get_max(const double t) const
    {
        const double p1 = max_inc + t;
        const double p2 = max_dec - t;
        return std::max({p1, p2, max_fixed});
    }

    double get_min(const double t) const
    {
        const double p1 = min_inc + t;
        const double p2 = min_dec - t;
        return std::min({p1, p2, min_fixed});
    }

    double get_span(const double t) const
    {
        return get_max(t) - get_min(t);
    }
};

int main()
{
    int n;
    std::cin >> n;

    Range horizontal(true), vertical(false);
    for (int i = 0; i < n; ++i)
    {
        int64_t x, y;
        char d;
        std::cin >> x >> y >> d;

        horizontal.add(x, d);
        vertical.add(y, d);
    }

    std::vector<double> cp;
    cp.emplace_back(0);
    cp.emplace_back(inf);
    horizontal.get_events(cp);
    vertical.get_events(cp);

    double ans = inf;
    for (const auto t : cp)
    {
        ans = std::min(ans, horizontal.get_span(t) * vertical.get_span(t));
    }
    std::cout << std::fixed << std::setprecision(4) << ans << std::endl;

    return 0;
}
