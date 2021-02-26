
#include <iostream>

//tests input to see if it is prime
bool test(int number) {

    if (number <= 1)
        return false;

    for (int temp = 2; temp < number; temp++)
        if (number % temp == 0)
            return false;

    return true;
}

int main()
{
    std::cout << "Input an integer:\n";
    int input;
    std::cin >> input;

    bool integer = test(input);

    if (integer == true)
        std::cout << input << " is prime.\n";

    else
        std::cout << input << " is not prime.\n";
}


