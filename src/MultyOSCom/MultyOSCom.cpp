#include "MultyOSCom.h"

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#elif defined(__unix__)
    system("clear");
#endif
}

void pauseTerminal()
{
#ifdef _WIN32
    system("pause");
#elif defined(__unix__) 
    system("read -p \"Press any key to resume or press Ctrl-C to abort ...\" any_key");
#endif
}