#include <iostream>

int main()
{
    int H, W, h, w;
    std::cin >> H >> W >> h >> w;
    std::cout << (H - h) * (W - w) << std::endl;
    return 0;
}
