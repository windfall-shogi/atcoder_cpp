#include <iostream>
#include <string>

enum Direction
{
    RIGHT,
    UP,
    LEFT,
    DOWN,
    SIZE
};
const Direction rot_l[SIZE] = {UP, LEFT, DOWN, RIGHT};
const Direction rot_r[SIZE] = {DOWN, RIGHT, UP, LEFT};

const int dx[SIZE] = {+1, 0, -1, 0};
const int dy[SIZE] = {0, +1, 0, -1};

bool search(const std::string &s, std::string::const_iterator it,
            const int x, const int y, int x0, int y0, Direction d)
{
    for (; it != s.end(); ++it)
    {
        if (*it == 'F')
        {
            x0 += dx[d];
            y0 += dy[d];
        }
        else
        {
            ++it;

            Direction tmp = rot_l[d];
            bool result = search(s, it, x, y, x0, y0, tmp);
            if (result)
            {
                return true;
            }

            tmp = rot_r[d];
            result = search(s, it, x, y, x0, y0, tmp);
            return result;
        }
    }

    return x == x0 && y == y0;
}

int main()
{
    std::string s;
    std::cin >> s;
    int x, y;
    std::cin >> x >> y;

    const bool result = search(s, s.begin(), x, y, 0, 0, RIGHT);
    std::cout << (result ? "Yes" : "No") << std::endl;
    return 0;
}
