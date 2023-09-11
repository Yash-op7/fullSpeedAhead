#include <iostream>
#include <cstdlib> // for rand() and srand() functions
#include <ctime>   // for time() function

int main()
{
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int randomNumber = (std::rand() % 100) + 1;

    // Print the random number
    std::cout << "Random number between 1 and 100: " << randomNumber << std::endl;

    return 0;
}
