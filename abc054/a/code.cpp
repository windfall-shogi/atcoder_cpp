#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    if (a == b)
    {
        std::cout << "Draw";
    }
    else
    {
        a = (a + 11) % 13;
        b = (b + 11) % 13;
        std::cout << (a > b ? "Alice" : "Bob");
    }
    std::cout << std::endl;

    return 0;
}
