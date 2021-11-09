#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> xs(n), ys(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> xs[i] >> ys[i];
    }

    const int64_t mod = (std::abs(xs[0]) + std::abs(ys[0])) % 2;
    for (int i = 1; i < n; ++i)
    {
        if (mod != (std::abs(xs[i]) + std::abs(ys[i])) % 2)
        {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    std::vector<int64_t> ds;
    for (int i = 30; i >= 0; --i)
    {
        ds.emplace_back(static_cast<int64_t>(1) << i);
    }
    if (mod == 0)
    {
        ds.emplace_back(1);
    }

    std::cout << ds.size() << std::endl;
    for (const auto d : ds)
    {
        std::cout << d << ' ';
    }
    std::cout << std::endl;

    for (int i = 0; i < n; ++i)
    {
        const int64_t u = xs[i] + ys[i], v = xs[i] - ys[i];
        int64_t p = 0, q = 0;
        for (const auto d : ds)
        {
            int u_dir, v_dir;
            if (p <= u)
            {
                p += d;
                u_dir = 1;
            }
            else
            {
                p -= d;
                u_dir = -1;
            }
            if (q <= v)
            {
                q += d;
                v_dir = 1;
            }
            else
            {
                q -= d;
                v_dir = -1;
            }

            if (u_dir == 1 && v_dir == 1)
            {
                std::cout << 'R';
            }
            else if (u_dir == 1 && v_dir == -1)
            {
                std::cout << 'U';
            }
            else if (u_dir == -1 && v_dir == -1)
            {
                std::cout << 'L';
            }
            else
            {
                std::cout << 'D';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
