#include <iostream>

int main()
{
    int64_t A, B;
    std::cin >> A >> B;
    bool easy = true;
    while (A > 0 && B > 0)
    {
        const int i = A % 10;
        const int j = B % 10;
        if (i + j >= 10)
        {
            easy = false;
            break;
        }
        A /= 10;
        B /= 10;
    }

    std::cout << (easy ? "Easy" : "Hard") << std::endl;

    return 0;
}
