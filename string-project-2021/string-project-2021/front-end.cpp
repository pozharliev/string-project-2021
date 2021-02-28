#include <iostream>
#include <conio.h>
#include <windows.h>
#include "front-end.h"

using namespace std;

//Varible for handling stdout
HANDLE hStdoutFrontEnd;

/*
	Varible for dificulties
	1 - easy
	2 - medium
	3 - hard
*/
int difficulties = 1;

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

//Print the settings
void printSettings(bool firstActive, bool secondActive)
{
	//Clear screen
	goToXY(0, 0);

	//Print the settings
	cout << "    ===========================================================" << endl;
	cout << "       _____ ______ _______ _______ _____ _   _  _____  _____" << endl;
	cout << "      / ____| ____ |__   __|__   __|_   _| \\ | |/ ____|/ ____|" << endl;
	cout << "     | (___ | |__     | |     | |    | | |  \\| | |  __| (___" << endl;
	cout << R"(      \___ \|  __|    | |     | |    | | | . ` | | |_ |\___ \)" << endl;
	cout << "      ____) | |____   | |     | |   _| |_| |\\  | |__| |____) |" << endl;
	cout << "     |_____/|______|  |_|     |_|  |_____|_| \\_|\\_____|_____/" << endl;
	cout << endl;
	cout << "    ===========================================================" << endl;

	//Check which choice is active
	cout << " "; if (firstActive)  cout << "-> ";  else cout << "   "; cout << "Difficulti: "; if (difficulties == 1)  cout << "Easy";  else if (difficulties == 2)  cout << "Medium"; else if (difficulties == 3)  cout << "Hard"; cout << endl;
	cout << " "; if (secondActive)  cout << "-> ";  else cout << "   "; cout << "Back" << endl;

	//Get ch
	const char ch = _getch();

	//Change active choice
	if (ch == 's' || ch == 'S' || ch == 'w' || ch == 'W')
	{
		if (secondActive)
		{
			printSettings(true, false);
		}

		if (firstActive)
		{
			printSettings(false, true);
		}
	}


	//Check for enter
	if (ch == '\r')
	{
		if (firstActive)
		{
			//Change setting
			if (difficulties == 1 || difficulties == 2)
			{	
				difficulties++;
			}
			else if (difficulties == 3)
			{
				difficulties = 1;
			}

			//Clear screen
			system("CLS");

			//print settings
			printSettings(true, false);
		}

		if (secondActive)
		{
			//Clear screen
			system("CLS");

			//Back to menu
			printMenu(true, false, false, false, false, false);
		}

	}
}

void printAbout()
{
	//Clear screen
	system("CLS");

	//print About
	cout << "    ==========================================" << endl;
	cout << "                ____   ____  _    _ _______" << endl;
	cout << "          /\\   |  _ \\ / __ \\| |  | |__   __|" << endl;
	cout << "         /  \\  | |_) | |  | | |  | |  | |" << endl;
	cout << "        / /\\ \\ |  _ <| |  | | |  | |  | |   " << endl;
	cout << "       / ____ \\| |_) | |__| | |__| |  | |" << endl;
	cout << "      /_/    \\_\\____/ \\____/ \\____/   |_|" << endl;
	cout << "    ==========================================" << endl;

	cout << endl;
	cout << "   String Project 2021" << endl;
	cout << "   Word game made in vanilla C++." << endl;
	cout << endl;
	cout << "   Participants:" << endl;
	cout << "   Atanas Pozharliev - ABPozharliev19@codingburgas.bg - Front - End Developer" << endl;
	cout << "   Stoyan Ivanov - SSIvanov19@codingburgas.bg - Quality Assurance" << endl;
	cout << "   Stas Uzunov - SSUzunov19@codingburgas.bg - C++ Developer" << endl;
	cout << "   Stefan Hristov - SHHristov19@codingburgas.bg - Scrum Trainer" << endl;
	cout << endl;
	cout << "   Team VAVILON" << endl;
	cout << endl;
	cout << "   -> Back" << endl;

	//Wait for input
	const char ch = _getch();

	//Clear screen
	system("CLS");

	printMenu(false, false, false, false, true, false);
}


void printHowToPlay()
{
	//Clear screen
	system("CLS");

	//print How to play
	cout << "    ==================================================" << endl;
	cout << "	 _    _  ______          __  _______ ____" << endl;
	cout << "	| |  | |/ __ \\ \\        / / |__   __/ __ \\" << endl;
	cout << "	| |__| | |  | \\ \\  /\\  / /     | | | |  | |" << endl;
	cout << "	|  __  | |  | |\\ \\/  \\/ /      | | | |  | |" << endl;
	cout << "	| |  | | |__| | \\  /\\  /       | | | |__| |" << endl;
	cout << "	|_|  |_|\\____/   \\/  \\/   _    |_|  \\____/ " << endl;
	cout << "	     |  __ \\| |        /\\\\ \\   / /" << endl;
	cout << "	     | |__) | |       /  \\\\ \\_/ /" << endl;
	cout << "	     |  ___/| |      / /\\ \\\\   /" << endl;
	cout << "	     | |    | |____ / ____ \\| |" << endl;
	cout << "	     |_|    |______/_/    \\_\\_|" << endl;
	cout << "    ==================================================" << endl;

	cout << endl;
	cout << "   Welcome to your path of becoming wizard." << endl << "   Here at the wizard academy you are going to learn how to spell your spells." << endl;
	cout << endl;
	cout << "   Write the word shown on the screen, before it fells out!" << endl << "   You can chose on of the 3 difficulties: Easy, Medium and Hard:" << endl;
	cout << "     For Easy - Write 5 words" << endl; 
	cout << "     For Medium - Write 10 words" << endl;
	cout << "     For Hard - Write 5 words" << endl;
	cout << endl;
	cout << "   And don't forget to have fun, while playing." << endl << endl;

	cout << " -> Back" << endl;

	//Wait for input
	const char ch = _getch();

	//Clear screen
	system("CLS");

	printMenu(false, false, false, true, false, false);
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
			system("CLS");
			printSettings(true, false);
		}

		if (fourthActive)
		{
			//Print How to Play
			printHowToPlay();
		}

		if (fifthActive)
		{
			//Print About Section
			printAbout();
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