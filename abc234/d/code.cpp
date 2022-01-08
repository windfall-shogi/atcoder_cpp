#include <iostream>
#include <queue>
#include <functional>
#include <vector>

int main()
{
    int64_t N, K;
    std::cin >> N >> K;
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> queue;
    for (int64_t i = 1; i <= N; ++i)
    {
        int64_t tmp;
        std::cin >> tmp;

        if (queue.size() < K)
        {
            queue.push(tmp);
        }
        else
        {
            if (tmp > queue.top())
            {
                queue.pop();
                queue.push(tmp);
            }
        }
        if (queue.size() >= K)
        {
            std::cout << queue.top() << std::endl;
        }
    }
    return 0;
}
