#include <iostream>
#include <vector>

bool check(const std::vector<int> &ts, const std::vector<int> &xs, const std::vector<int> &ys)
{
    int t = 0, x = 0, y = 0;
    for (size_t i = 0; i < ts.size(); ++i)
    {
        const int dt = ts[i] - t;
        const int dx = std::abs(xs[i] - x);
        const int dy = std::abs(ys[i] - y);

        if (dx + dy > dt)
        {
            return false;
        }

        const int m = dt - (dx + dy);
        if (m % 2 != 0)
        {
            return false;
        }

        t = ts[i];
        x = xs[i];
        y = ys[i];
    }
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> ts(n), xs(n), ys(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ts[i] >> xs[i] >> ys[i];
    }

    std::cout << (check(ts, xs, ys) ? "Yes" : "No") << std::endl;
    return 0;
}
