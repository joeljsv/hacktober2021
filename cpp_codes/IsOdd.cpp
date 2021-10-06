#include <iostream>

bool IsOdd(int number)
{
    return number % 2 != 0;
}

int main()
{
    std::cout << "Please enter a number: ";
    int number;
    std::cin >> number;
    std::cout << number;
    if(IsOdd(number))
    {
        std::cout << " is an odd number";
    }
    else
    {
        std::cout << " is an even number";
    }
    std::cout << std::endl;

}
