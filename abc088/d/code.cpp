#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>

int main()
{
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> ss(h);
    std::vector<std::vector<int>> distances(h);
    const int unreached = 2 * h * w;
    for (int i = 0; i < h; ++i)
    {
        std::cin >> ss[i];

        distances[i].resize(w);
        std::fill(distances[i].begin(), distances[i].end(), unreached);
    }
    distances[0][0] = 1;

    const int dx[4] = {+1, 0, -1, 0};
    const int dy[4] = {0, +1, 0, -1};

    std::stack<std::pair<int, int>> stack;
    stack.emplace(0, 0);
    while (!stack.empty())
    {
        const std::pair<int, int> p = stack.top();
        stack.pop();

        const int y1 = p.first, x1 = p.second;
        for (int i = 0; i < 4; ++i)
        {
            const int y2 = y1 + dy[i], x2 = x1 + dx[i];
            if (x2 < 0 || y2 < 0 || x2 >= w || y2 >= h)
            {
                continue;
            }
            if (ss[y2][x2] == '#')
            {
                continue;
            }

            if (distances[y2][x2] > distances[y1][x1] + 1)
            {
                stack.emplace(y2, x2);
                distances[y2][x2] = distances[y1][x1] + 1;
            }
        }
    }

    if (distances[h - 1][w - 1] == unreached)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        int black = 0;
        for (const auto &s : ss)
        {
            for (const char c : s)
            {
                if (c == '#')
                {
                    ++black;
                }
            }
        }

        std::cout << h * w - black - distances[h - 1][w - 1] << std::endl;
    }

    return 0;
}
