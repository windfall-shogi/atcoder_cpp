#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int64_t N, A, B, P, Q, R, S;
    std::cin >> N >> A >> B;
    std::cin >> P >> Q >> R >> S;

    const int64_t lower1 = std::max(1 - A, 1 - B);
    const int64_t upper1 = std::min(N - A, N - B);
    const int64_t lower2 = std::max(1 - A, B - N);
    const int64_t upper2 = std::min(N - A, B - 1);

    const auto R_backup = R;
    while (P <= Q)
    {
        R = R_backup;
        while (R <= S)
        {
            bool flag = false;
            const auto k = P - A;
            if (k >= lower1 && k <= upper1)
            {
                if (R == B + k)
                {
                    flag = true;
                }
            }

            if (!flag && k >= lower2 && k <= upper2)
            {
                if (R == B - k)
                {
                    flag = true;
                }
            }

            if (flag)
            {
                std::cout << '#';
            }
            else
            {
                std::cout << '.';
            }

            ++R;
        }
        std::cout << std::endl;
        ++P;
    }

    return 0;
}
