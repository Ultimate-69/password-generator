#include <random>
#include <iostream>

int main()
{
    const char* letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* symbols = "!@#$%&*?";
    const char* numbers = "0123456789";

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> randomLetter(0, 51);
    std::uniform_int_distribution<std::mt19937::result_type> randomSymbol(0, 7);
    std::uniform_int_distribution<std::mt19937::result_type> randomNumber(0, 9);
    std::uniform_int_distribution<std::mt19937::result_type> iType(0, 10);

    int length = 0;

    std::cout << "Enter the password length: ";
    try
    {    
        std::cin >> length;
    }
    catch(const std::exception& e)
    {
        std::cout << "An error was encountered when getting the password length.";
    }

    std::string password;

    for (int i = 0; i < length; i++)
    {
       int typeOfLetter = iType(rng);
       if (typeOfLetter <= 5)
       {
            password += letters[randomLetter(rng)];
       }
       else if (typeOfLetter <= 8)
       {
            password += numbers[randomNumber(rng)];
       }
       else if (typeOfLetter <= 10)
       {
            password += symbols[randomSymbol(rng)];
       }

    }

    std::cout << "Your password: " << password << std::endl;
    std::cout << "Press ENTER to exit." << std::endl;
    std::cin.sync();
    std::cin.ignore();
}