#include "BulletProof.h"

void cleanPipe()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

// bool checkEntr()
// {
//     if (std::cin.get() == '\n')
//         return true;


// }

void bulProof(int& input, const int &lowBound, const int &upBound)
{
    bool flag = true;
    while (flag)
    {
        cleanPipe();
        if (std::cin.fail())
        {
            std::cout << "\n\tPlease enter number within range" << std::endl;
            std::cout << ">>";
            std::cin >> input;
        }
        else if (lowBound > input || input > upBound)
        {
            std::cout << "\n\tPlease enter a number between "
                      << lowBound << " and " << upBound << std::endl;
            std::cout << ">>";
            std::cin >> input;
        }
        else
            flag = false;
    }
}

void bulProofGenInput(int &input, const int &lowBound)
{
    bool flag = true;
    while (flag)
    {
        cleanPipe();
        if (std::cin.fail())
        {
            std::cout << "\n\tPlease enter numer\n"
                      << ">> ";
            std::cin >> input;
        }
        else if (lowBound > input)
        {
            std::cout << "\n\tPlease enter number grather then "
                      << std::to_string(lowBound) << "\n>>";
            std::cin >> input;
        }
        else
            flag = false;
    }
}