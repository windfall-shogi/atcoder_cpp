#include <iostream>

int main()
{
    int64_t h, w;
    std::cin >> h >> w;

    if (h % 3 == 0 || w % 3 == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    // 縦に3分割、横に3分割した時の差
    int64_t result = std::min(h,w);

    // 縦に先に分割する場合
    {
        const int64_t y = h * w / 3 / w;
        const int64_t x = w / 2;
        for (int i = 0; i < 3; ++i)
        {
            const int64_t a = (y + i) * w;
            const int64_t b = (h - (y + i)) * (w / 2);
            const int64_t c = (h - (y + i)) * (w - w / 2);

            const int64_t max = std::max(a, c);
            const int64_t min = std::min(a, b);
            result = std::min(result, max - min);
        }
    }

    // 横に先に分割する場合
    {
        const int64_t x = h * w / 3 / h;
        const int64_t y = h / 2;
        for (int i = 0; i < 3; ++i)
        {
            const int64_t a = (x + i) * h;
            const int64_t b = (w - (x + i)) * (h / 2);
            const int64_t c = (w - (x + i)) * (h - h / 2);

            const int64_t max = std::max(a, c);
            const int64_t min = std::min(a, b);
            result = std::min(result, max - min);
        }
    }

    std::cout << result << std::endl;
    return 0;
}
