#include <iostream>

int main()
{
    int64_t x, y;
    std::cin >> x >> y;

    int count = 0;
    do
    {
        ++count;
        x *= 2;
    } while (x <= y);

    std::cout << count << std::endl;
    return 0;
}
