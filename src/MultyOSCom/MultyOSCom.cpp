#include "MultyOSCom.h"

void clearScreen()
{
#if defined(_WIN32)
    system("cls");
#elif defined(__unix__)
    system("clear");
#endif
}

void pauseTerminal()
{
#if defined(_WIN32)
    system("pause");
#elif defined(__unix__) 
    system("read -p \"Press any key to resume or press Ctrl-C to abort ...\" any_key");
#endif
}