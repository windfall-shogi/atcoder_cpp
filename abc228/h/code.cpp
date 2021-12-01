#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>

// https://atcoder.jp/contests/abc228/submissions/27341071
int64_t floor_div(int64_t x, int64_t y) { return x / y - (((x ^ y) < 0) && (x % y)); }

struct Line
{
    int64_t a, b;
    Line() : a(), b() {}
    explicit Line(int64_t a_, int64_t b_) : a(a_), b(b_) {}
    int64_t eval(int64_t x) const { return a * x + b; }
};

// Convex Hull Trickのかなり特殊な状況の場合の実装
// 追加される直線の傾きが単調減少である
// クエリの値が単調増加である
class ConvexHullTrick
{
    std::deque<Line> line;

public:
    ConvexHullTrick() : line() {}

    void add_line(Line l)
    {
        while (line.size() >= 2)
        {
            // 傾きが単調減少なので、常に最後の直線について削除するか判定すればいい
            Line m = line[line.size() - 1], n = line[line.size() - 2];
            if (floor_div(m.b - n.b, n.a - m.a) < floor_div(l.b - m.b, m.a - l.a))
            {
                break;
            }
            line.pop_back();
        }
        line.push_back(l);
    }

    int64_t get_min(int64_t x)
    {
        // クエリが単調増加なので、一度でも最小でなくなった直線は二度と最小にはならない
        while (line.size() >= 2 && line[0].eval(x) > line[1].eval(x))
        {
            line.pop_front();
        }
        return line[0].eval(x);
    }
};

// https://atcoder.jp/contests/abc228/submissions/27461718
int main()
{
    int N, X;
    std::cin >> N >> X;
    std::vector<std::pair<int, int>> data(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> data[i].first >> data[i].second;
    }
    std::sort(data.begin(), data.end());

    std::vector<int64_t> D(N + 1);
    std::vector<int64_t> E(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        D[i] = D[i - 1] + data[i].second;
        E[i] = E[i - 1] + static_cast<int64_t>(data[i].first) * data[i].second;
    }

    ConvexHullTrick cht;
    constexpr int64_t INF = 1LL << 60;
    std::vector<int64_t> dp(N + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        cht.add_line(Line(-D[i - 1], E[i - 1] + dp[i - 1] + X));
        dp[i] = (D[i] * data[i].first - E[i]) + cht.get_min(data[i].first);
    }

    std::cout << dp[N] << std::endl;

    return 0;
}
