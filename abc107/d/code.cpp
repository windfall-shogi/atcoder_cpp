#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
struct Bit
{
public:
    Bit(const int size) : array(size + 1) {}

    template <typename InputIterator>
    void initialize(InputIterator first)
    {
        for (int x = 1; x < static_cast<int>(array.size()); ++x)
        {
            array[x] = first + x - 1;
        }
        for (int x = 1; x < static_cast<int>(array.size()); ++x)
        {
            const int y = x + (x & -x);
            if (y < static_cast<int>(array.size()))
            {
                array[y] += array[x];
            }
        }
    }

    void add(const int i, const int v)
    {
        for (int x = i; x < static_cast<int>(array.size()); x += x & -x)
        {
            array[x] += v;
        }
    }

    T sum(const int i) const
    {
        T s = 0;
        for (int x = i; x > 0; x -= x & -x)
        {
            s += array[x];
        }
        return s;
    }

private:
    std::vector<T> array;
};

bool check(const std::vector<int> &as, const int k)
{
    Bit<int> bit(as.size() * 2 + 10);

    const int offset = as.size() + 5;
    int64_t count = 0;
    int64_t sum = 0;

    bit.add(offset, 1);
    for (const auto a : as)
    {
        if (a >= k)
        {
            ++count;
        }
        else
        {
            --count;
        }

        sum += bit.sum(offset + count);
        bit.add(offset + count, 1);
    }

    const auto n = ((as.size() - 1) * as.size() / 2 + as.size() + 1) / 2;
    return sum >= n;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    std::vector<int> ordered(n);
    std::copy(as.begin(), as.end(), ordered.begin());
    std::sort(ordered.begin(), ordered.end());
    ordered.erase(std::unique(ordered.begin(), ordered.end()), ordered.end());

    int left = 0, right = ordered.size();
    while (left + 1 != right)
    {
        int middle = (left + right) / 2;
        if (check(as, ordered[middle]))
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }

    std::cout << ordered[left] << std::endl;

    return 0;
}
