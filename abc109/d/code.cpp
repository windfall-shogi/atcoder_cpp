#include <iostream>
#include <vector>

struct Move
{
    int y1, x1, y2, x2;
};

int TABLE[500][500];

int main()
{
    // コインが0枚のマスも「コインが偶数枚あるマス」とみなすらしい
    // 問題文で「マス(i, j)にはa_ij枚のコインが置かれています。」とあり、
    // 0 <= a_ij <= 9
    // なので、0枚でもコインがあると言えなくはない。
    // 限りなく出題ミスに近いと思う
    
    int h, w;
    std::cin >> h >> w;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            std::cin >> TABLE[i][j];
        }
    }

    std::vector<Move> moves;
    for (int i = 0; i < h - 1; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (TABLE[i][j] % 2 == 1)
            {
                moves.emplace_back(Move{i, j, i + 1, j});

                --TABLE[i][j];
                ++TABLE[i + 1][j];
            }
        }
    }
    for (int j = 0; j < w - 1; ++j)
    {
        if (TABLE[h - 1][j] % 2 == 1)
        {
            moves.emplace_back(Move{h - 1, j, h - 1, j + 1});

            --TABLE[h - 1][j];
            ++TABLE[h - 1][j + 1];
        }
    }

    std::cout << moves.size() << std::endl;
    for (const auto &e : moves)
    {
        std::cout << e.y1 + 1 << ' ' << e.x1 + 1 << ' ' << e.y2 + 1 << ' ' << e.x2 + 1 << std::endl;
    }

    return 0;
}
