#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

struct Node
{
    int add1, mul10;
};

int search(const std::vector<Node> &nodes)
{
    std::vector<int> d(nodes.size(), static_cast<int>(nodes.size()));
    d[1] = 0;

    std::deque<int> deque;
    deque.push_back(1);

    while (!deque.empty())
    {
        const int index = deque.front();
        deque.pop_front();
        if (index == 0)
        {
            break;
        }

        const auto &n = nodes[index];
        if (d[index] < d[n.mul10])
        {
            d[n.mul10] = d[index];
            deque.push_front(n.mul10);
        }
        if (d[index] + 1 < d[n.add1])
        {
            d[n.add1] = d[index] + 1;
            deque.push_back(n.add1);
        }
    }

    return d[0] + 1;
}

int main()
{
    int k;
    std::cin >> k;

    std::vector<Node> nodes(k);
    nodes[0] = {0, 0};
    for (int i = 1; i <= k - 1; ++i)
    {
        nodes[i] = {(i + 1) % k, (i * 10) % k};
    }

    std::cout << search(nodes) << std::endl;
    return 0;
}
