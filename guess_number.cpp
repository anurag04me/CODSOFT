#include <iostream>
#include <cstdlib> // For random number generation
#include <ctime>   // For seeding the random number generator

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100." << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number (" << secretNumber << ") in " << attempts << " attempts." << std::endl;
            break;
        }
    }

    return 0;
}
