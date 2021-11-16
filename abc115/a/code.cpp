#include <iostream>

int main()
{
    int d;
    std::cin >> d;
    std::cout << "Christmas";
    for (int i = d; i < 25; ++i)
    {
        std::cout << " Eve";
    }
    std::cout << std::endl;
    return 0;
}
