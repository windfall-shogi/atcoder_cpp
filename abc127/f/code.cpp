#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int main()
{
    int64_t q;
    std::cin >> q;
    std::priority_queue<int64_t> left;
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> right;

    int64_t min_value = 0;
    for (int64_t i = 0; i < q; ++i)
    {
        int n;
        std::cin >> n;
        if (n == 1)
        {
            int64_t a, b;
            std::cin >> a >> b;

            min_value += b;
            left.push(a);
            right.push(a);
            if (left.top() > right.top())
            {
                const int64_t x = left.top();
                left.pop();
                const int64_t y = right.top();
                right.pop();

                left.push(y);
                right.push(x);

                min_value += std::abs(x - y);
            }
        }
        else
        {
            std::cout << left.top() << ' ' << min_value << std::endl;
        }
    }

    return 0;
}
