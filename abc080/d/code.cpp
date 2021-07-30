#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>

struct Program
{
    int s, t, c;
};

struct CompareA
{
    bool operator()(const Program p1, const Program p2) const
    {
        // trueになるとp1はp2より後ろになる
        if (p2.s == p1.s)
        {
            return p2.c < p1.c;
        }
        return p2.s < p1.s;
    }
};

struct CompareB
{
    bool operator()(const Program p1, const Program p2) const
    {
        // trueになるとp1はp2より後ろになる
        if (p2.t == p1.t)
        {
            return p2.c < p1.c;
        }
        return p2.t < p1.t;
    }
};

int main()
{
    int n, c;
    std::cin >> n >> c;

    std::vector<std::vector<std::pair<int, int>>> buffer(c);
    for (int i = 0; i < n; ++i)
    {
        int s, t, channel;
        std::cin >> s >> t >> channel;
        buffer[channel - 1].emplace_back(s, t);
    }

    std::priority_queue<Program, std::vector<Program>, CompareA> qa;
    std::priority_queue<Program, std::vector<Program>, CompareB> qb;

    for (int i = 0; i < c; ++i)
    {
        auto &buf = buffer[i];
        std::sort(buf.begin(), buf.end());
        for (auto it1 = buf.begin(); it1 != buf.end(); ++it1)
        {
            if (it1->first < 0)
            {
                continue;
            }
            for (auto it2 = std::next(it1); it2 != buf.end(); ++it2)
            {
                if (it1->second == it2->first)
                {
                    it1->second = it2->second;

                    it2->first = it2->second = -1;

                    continue;
                }
                break;
            }
        }

        for (const auto &e : buf)
        {
            if (e.first < 0)
            {
                continue;
            }

            Program p{e.first, e.second, i + 1};
            qa.push(p);
        }
    }

    size_t ans = 0;
    Program next, finished;
    while (!qa.empty())
    {
        next = qa.top();

        if (qb.empty())
        {
            qb.push(next);
            qa.pop();

            ans = std::max(ans, qb.size());

            finished = qb.top();
        }
        else
        {
            while (!qb.empty())
            {
                if (finished.t < next.s)
                {
                    qb.pop();
                }
                else if (finished.t == next.s && finished.c == next.c)
                {
                    qb.pop();
                }
                else
                {
                    break;
                }
                finished = qb.top();
            }

            qb.push(next);
            finished = qb.top();
            ans = std::max(ans, qb.size());

            qa.pop();
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
