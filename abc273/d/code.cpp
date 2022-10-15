#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

int main()
{
    int64_t H, W, rs, cs;
    std::cin >> H >> W >> rs >> cs;
    int64_t N;
    std::cin >> N;

    std::unordered_map<int64_t, std::vector<int64_t>> wall_r, wall_c;
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t r, c;
        std::cin >> r >> c;
        wall_r[r].emplace_back(c);
        wall_c[c].emplace_back(r);
    }
    for (auto &e : wall_r)
    {
        std::sort(e.second.begin(), e.second.end());
    }
    for (auto &e : wall_c)
    {
        std::sort(e.second.begin(), e.second.end());
    }

    int64_t Q;
    std::cin >> Q;
    const std::unordered_map<char, int64_t> dr{{'L', 0}, {'R', 0}, {'U', -1}, {'D', 1}},
        dc{{'L', -1}, {'R', 1}, {'U', 0}, {'D', 0}};
    for (int64_t i = 0; i < Q; ++i)
    {
        char d;
        int64_t l;
        std::cin >> d >> l;
        if (d == 'L' || d == 'R')
        {
            int64_t new_c = std::clamp<int64_t>(cs + l * dc.at(d), 1LL, W);

            const auto &wall = wall_r[rs];
            if (!wall.empty())
            {
                if (d == 'L')
                {
                    auto it = std::upper_bound(wall.begin(), wall.end(), cs);
                    if (it != wall.begin())
                    {
                        --it;
                        new_c = std::max(*it + 1, new_c);
                    }
                }
                else
                {
                    auto it = std::lower_bound(wall.begin(), wall.end(), cs);
                    if (it != wall.end())
                    {
                        new_c = std::min(*it - 1, new_c);
                    }
                }
            }
            cs = new_c;
        }
        else
        {
            int64_t new_r = std::clamp<int64_t>(rs + l * dr.at(d), 1LL, H);

            const auto &wall = wall_c[cs];
            if (!wall.empty())
            {
                if (d == 'U')
                {
                    auto it = std::upper_bound(wall.begin(), wall.end(), rs);
                    if (it != wall.begin())
                    {
                        --it;
                        new_r = std::max(*it + 1, new_r);
                    }
                }
                else
                {
                    auto it = std::lower_bound(wall.begin(), wall.end(), rs);
                    if (it != wall.end())
                    {
                        new_r = std::min(*it - 1, new_r);
                    }
                }
            }
            rs = new_r;
        }
        std::cout << rs << ' ' << cs << std::endl;
    }

    return 0;
}
