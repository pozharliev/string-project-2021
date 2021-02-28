#include <iostream>
#include <Windows.h>
#include "front-end.h"
#include "back-end.h"

using namespace std;

HANDLE hStdout;

int main()
{
    //Set console to  windows 1251 codepage, so it can dispaly bulgarian text
    SetConsoleOutputCP(1251);

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    //Check if console output handle is invalid
    if (hStdout == INVALID_HANDLE_VALUE)
    {
        //Tell user that there is a problem
        cout << "There is problem with the console handler and the game can not load properly!";

        //Exit the program
        return 0;
    }
    
    //Set text to white
    SetConsoleTextAttribute(hStdout, 15);

    saveStdHandle();
    
    while (true)
    {
        printMenu(true, false, false, false, false, false);
    }
    
}
