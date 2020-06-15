#include <iostream>

int main()
{
    char c;
    std::cin >> c;
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
    {
        std::cout << "vowel";
    }
    else
    {
        std::cout << "consonant";
    }
    std::cout << std::endl;

    return 0;
}
