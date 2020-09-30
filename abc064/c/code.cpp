#include <iostream>
#include <vector>
#include <array>

enum Color
{
    GRAY,
    BROWN,
    GREEN,
    LIGHT_BLUE,
    BLUE,
    YELLOW,
    ORANGE,
    RED,
    WHITE,
    SIZE
};

Color GetColor(const int rate)
{
    if (rate >= 3200)
    {
        return WHITE;
    }
    else
    {
        return static_cast<Color>(rate / 400);
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    std::array<int, SIZE> count = {0};
    for (const auto s : arr)
    {
        ++count[GetColor(s)];
    }

    int c = 0;
    for (int i = 0; i <= RED; ++i)
    {
        if (count[i] > 0)
        {
            ++c;
        }
    }

    int min, max;
    if (count[WHITE] > 0)
    {
        min = std::max(c, 1);
        // レートにない色も選べる
        // 確かに問題には自由に選べると書いてある
        // 例題でもレートにない色も選んでいる
        max = c + count[WHITE];
    }
    else
    {
        min = max = c;
    }

    std::cout << min << ' ' << max << std::endl;
    return 0;
}
