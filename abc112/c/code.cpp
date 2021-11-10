#include <iostream>
#include <vector>
#include <algorithm>

struct Position
{
    int x, y, h;
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<Position> ps(n);
    for (int i = 0; i < n; ++i)
    {
        int x, y, h;
        std::cin >> x >> y >> h;
        ps[i] = Position{x, y, h};
    }
    std::sort(ps.begin(), ps.end(), [](const Position &lhs, const Position &rhs)
              { return lhs.h > rhs.h; });

    const int least_h = ps[0].h;
    for (int cx = 0; cx <= 100; ++cx)
    {
        for (int cy = 0; cy <= 100; ++cy)
        {
            int max_h = 1000000000;
            int exact_h = ps[0].h + std::abs(ps[0].x - cx) + std::abs(ps[0].y - cy);
            bool ok = true;

            for (const auto &p : ps)
            {
                const int candidate = p.h + std::abs(cx - p.x) + std::abs(cy - p.y);
                if (p.h == 0)
                {
                    max_h = std::min(candidate, max_h);

                    if (max_h < least_h || max_h < exact_h)
                    {
                        ok = false;
                        break;
                    }
                }
                else
                {
                    if (exact_h != candidate)
                    {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok)
            {
                std::cout << cx << ' ' << cy << ' ' << exact_h << std::endl;
                return 0;
            }
        }
    }

    return 0;
}
