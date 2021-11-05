#include <vector>

// 参考: https://scrapbox.io/pocala-kyopro/%E8%BB%A2%E5%80%92%E6%95%B0
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
