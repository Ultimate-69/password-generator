#include <random>
#include <iostream>

int main()
{
    const char* letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 51); // Get random number in alphabet's range

    std::cout << letters[dist6(rng)] << std::endl;
}