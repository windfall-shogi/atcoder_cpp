#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
    int h, w, n;
    std::cin >> h >> w >> n;
    std::vector<std::pair<int, int>> arr;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        // 0-baseに変換
        arr.emplace_back(std::make_pair(a - 1, b - 1));
    }

    std::vector<int64_t> count(10);
    count[0] = static_cast<int64_t>(h - 2) * (w - 2);
    for (int i = 0; i < n; ++i)
    {
        bool buffer[5][5] = {{false}};

        int c_h = arr[i].first, c_w = arr[i].second;
        int o_h = c_h - 2, o_w = c_w - 2;
        int begin_h = std::max(o_h, 0), begin_w = std::max(o_w, 0);
        int end_h = std::min(c_h + 3, h), end_w = std::min(c_w + 3, w);
        for (int j = 0; j < i; ++j)
        {
            const auto &tmp = arr[j];
            if (tmp.first >= begin_h && tmp.first < end_h && tmp.second >= begin_w && tmp.second < end_w)
            {
                buffer[tmp.first - o_h][tmp.second - o_w] = true;
            }
        }

        std::vector<int> tmp_count(10);
        for (int r = begin_h; r < end_h - 2; ++r)
        {
            for (int c = begin_w; c < end_w - 2; ++c)
            {
                int black = 0;
                for (int p = 0; p < 3; ++p)
                {
                    for (int q = 0; q < 3; ++q)
                    {
                        if (buffer[r + p - o_h][c + q - o_w])
                        {
                            ++black;
                        }
                    }
                }
                ++tmp_count[black];
            }
        }
        for (int k = 0; k < 9; ++k)
        {
            count[k] -= tmp_count[k];
            count[k + 1] += tmp_count[k];
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << count[i] << std::endl;
    }
    return 0;
}
