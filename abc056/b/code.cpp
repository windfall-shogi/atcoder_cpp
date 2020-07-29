#include <iostream>

int main()
{
    int w, a, b;
    std::cin >> w >> a >> b;

    int d;
    if (a + w < b)
    {
        // 一つ目を基準として2つ目は右にある
        d = b - (a + w);
    }
    else if (a > b + w)
    {
        // 一つ目を基準として2つ目は左にある
        d = a - (b + w);
    }
    else
    {
        // 連結
        d = 0;
    }
    std::cout << d << std::endl;
    return 0;
}
