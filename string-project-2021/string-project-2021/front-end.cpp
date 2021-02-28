#include <iostream>
#include <conio.h>
#include <windows.h>
#include "front-end.h"

using namespace std;

HANDLE hStdoutFrontEnd;

//Get Handle of STD
void saveStdHandle() 
{
	hStdoutFrontEnd = GetStdHandle(STD_OUTPUT_HANDLE);
}

//Set cursor postion to XY cordinate
void goToXY(short x, short y)
{
	COORD cords;
	cords.X = x;
	cords.Y = y;
	SetConsoleCursorPosition(hStdoutFrontEnd, cords);
}

//Print the menu
void printMenu(bool firstActive, bool secondActive, bool thirdActive, bool fourthActive, bool fifthActive, bool sixthActive)
{
	//Clear screen
	goToXY(0, 0);

	//print the name of the game
	cout << "    ===========================================" << endl;
	cout << "	  __  __             _   " << endl;
	cout << "	 |  \\/  |           (_)  " << endl;
	cout << "	 | \\  / | __ _  __ _ _  ___ " << endl;
	cout << "	 | |\\/| |/ _` |/ _` | |/ __| " << endl;
	cout << "	 | |  | | (_| | (_| | | (__ " << endl;
	cout << "         |_|  |_|\\__,_|\\__, |_|\\___| " << endl;
	cout << "                       ___/ |   " << endl;
	cout << "           __         |____/        _  " << endl;
	cout << "           \\ \\        / /          | | " << endl;
	cout << "            \\ \\  /\\  / /__  _ __ __| |___ " << endl;
	cout << "             \\ \\/  \\/ / _ \\| '__/ _` / __| " << endl;
	cout << "              \\  /\\  / (_) | | | (_| \\__ \\ " << endl;
	cout << "               \\/  \\/ \\___/|_|  \\__,_|___/ " << endl;
	cout << "    ===========================================" << endl;

	cout << endl;
	cout << endl;

	//Check which choice is active
	cout << " "; if (firstActive)  cout << "-> ";  else cout << "   "; cout << "New Game " << endl;
	cout << endl;
	cout << " "; if (secondActive)  cout << "-> ";  else cout << "   "; cout << "Resume Game" << endl;
	cout << endl;
	cout << " "; if (thirdActive)  cout << "-> ";  else cout << "   "; cout << "Settings" << endl;
	cout << endl;
	cout << " "; if (fourthActive)  cout << "-> ";  else cout << "   "; cout << "How to play" << endl;
	cout << endl;
	cout << " "; if (fifthActive)  cout << "-> ";  else cout << "   "; cout << "About" << endl;
	cout << endl;
	cout << " "; if (sixthActive)  cout << "-> ";  else cout << "   "; cout << "Exit" << endl;

	//Get ch
	const char ch = _getch();

	//Change active choice
	if (ch == 's' || ch == 'S')
	{
		if (firstActive)
		{
			printMenu(false, true, false, false, false, false);
		}

		if (secondActive)
		{
			printMenu(false, false, true, false, false, false);
		}

		if (thirdActive)
		{
			printMenu(false, false, false, true, false, false);
		}

		if (fourthActive)
		{
			printMenu(false, false, false, false, true, false);
		}

		if (fifthActive)
		{
			printMenu(false, false, false, false, false, true);
		}

		if (sixthActive)
		{
			printMenu(true, false, false, false, false, false);
		}
	}

	//Change active choice
	if (ch == 'w' || ch == 'W')
	{
		if (firstActive)
		{
			printMenu(false, false, false, false, false, true);
		}

		if (secondActive)
		{
			printMenu(true, false, false, false, false, false);
		}

		if (thirdActive)
		{
			printMenu(false, true, false, false, false, false);
		}

		if (fourthActive)
		{
			printMenu(false, false, true, false, false, false);
		}

		if (fifthActive)
		{
			printMenu(false, false, false, true, false, false);
		}

		if (sixthActive)
		{
			printMenu(false, false, false, false, true, false);
		}
	}

	//Check for enter
	if (ch == '\r')
	{
		if (firstActive)
		{
			//New game and print board
			//newGame();
			//printBoard(true);
		}

		if (secondActive)
		{
			//Print board
			//printBoard(true);
		}

		if (thirdActive)
		{
			//Print Settings
			//printSettings(true, false);
		}

		if (fourthActive)
		{
			//Print How to Play
			//printHowToPlay();
		}

		if (fifthActive)
		{
			//Print About Section
			//printAbout();
		}

		if (sixthActive)
		{
			//Exit the game
			exit(3);
		}

	}
	else
	{
		printMenu(firstActive, secondActive, thirdActive, fourthActive, fifthActive, sixthActive);
	}
}