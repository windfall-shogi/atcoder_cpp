#include <iostream>

int main()
{
    int s, t, x;
    std::cin >> s >> t >> x;
    bool on;
    if (s < t)
    {
        on = s <= x && x < t;
    }
    else
    {
        on = s <= x || x < t;
    }
    std::cout << (on ? "Yes" : "No") << std::endl;
    return 0;
}
