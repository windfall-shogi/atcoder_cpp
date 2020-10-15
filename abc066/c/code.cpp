#include <iostream>
#include <deque>

int main()
{
    int n;
    std::cin >> n;
    std::deque<int> deque;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        if (i % 2 == 0)
        {
            deque.push_back(tmp);
        }
        else
        {
            deque.push_front(tmp);
        }
    }

    if (n % 2 == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cout << deque.back();
            deque.pop_back();
            if (i < n - 1)
            {
                std::cout << ' ';
            }
            else
            {
                std::cout << std::endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            std::cout << deque.front();
            deque.pop_front();
            if (i < n - 1)
            {
                std::cout << ' ';
            }
            else
            {
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
