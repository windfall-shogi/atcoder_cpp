#include <iostream>
#include <queue>
#include <vector>

struct Program
{
    int s, t, c;
};

struct CompareA
{
    bool operator()(const Program p1, const Program p2) const
    {
        // trueになるとp1はp2より後ろになる
        if(p2.s == p1.s){
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
        if(p2.t == p1.t){
            return p2.c < p1.c;
        }
        return p2.t < p1.t;
    }
};

int main()
{
    int n, c;
    std::cin >> n >> c;

    std::priority_queue<Program, std::vector<Program>, CompareA> qa;
    std::priority_queue<Program, std::vector<Program>, CompareB> qb;
    for (int i = 0; i < n; ++i)
    {
        Program tmp;
        std::cin >> tmp.s >> tmp.t >> tmp.c;
        qa.push(tmp);
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
