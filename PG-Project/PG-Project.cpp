#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <chrono> 
#include <thread>

const char numbers[10]{'1','2','3','4','5','6','7','8','9','0'};
const char letters[26]{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const char special[4]{ '#','$','!','&' };

char userChoice;
bool useSpecial;
int lenght = 0;

std::string password = "";

int main()
{
    srand(time(0)); // Generate seed of random using ctime

    std::cout << "Welcome to password generator\nDo you want to use special characters in your password? [y/n] : ";
    std::cin >> userChoice;
    if (userChoice == 'y') useSpecial = true;
    else useSpecial = false;

    std::cout << "Type lenght of your password : ";
    std::cin >> lenght;
    std::cout << "Generating your password!";
    
    auto begin = std::chrono::steady_clock::now();
    switch (useSpecial)
    {
    case 0:
        for (int i = 0; i < lenght; i++)
        {
            switch (rand() % 3)
            {
            case 0:
                password += numbers[rand() % 10];
                break;
            case 1:
                password += letters[rand() % 26];
                break;
            }
        }
        std::cout << std::endl << "Your password is : " << password;
        break;
    case 1:
        for (int i = 0; i < lenght; i++)
        {
            switch (rand() % 3)
            {
            case 0:
                password += numbers[rand() % 10];
                break;
            case 1:
                password += letters[rand() % 26];
                break;
            case 2:
                password += special[rand() % 4];
                break;
            }
        }
        std::cout << std::endl << "Your password is : " << password;
        break;
    }
    auto end = std::chrono::steady_clock::now();
    std::cout << std::endl << "Password has been generated for : " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms" << std::endl;
}