
#include "grand.h"
#include <iostream>
#include <string>  
#include <stdlib.h>     
#include <time.h>       
#include <Windows.h>

using namespace std;

void game()
{
    string word[60] = {
       "apple", "application", "apply", "appoint", "appointment", "appreciate",
       "blame", "blanket", "blind", "block", "blood", "blow",
       "chain", "chair", "chairman", "challenge", "chamber", "champion",
       "description", "desert", "deserve", "design", "designer", "desire",
       "enjoy", "enormous", "enough", "ensure", "enter", "enterprise",
       "family", "famous", "fan", "fantasy", "far", "farm",
       "goal", "God", "gold", "golden", "golf", "good",
       "happen", "happy", "hard", "hardly", "hat", "hate",
       "leave", "left", "leg", "legacy", "legal", "legend",
       "media", "medical", "medication", "medicine", "medium", "meet"
    };

    int numWords, sec;
    int index[60], spaces[60], whileSpaces[60], keep[60], j = 0, k, point = 0;
    bool endGame = false;
    string answer[60], words[60];

    cout << "How many words are you looking to play with? (max 60 words)" << endl;
    cin >> numWords;
    cout << "How fast you want to play (answer in milliseconds)?" << endl;
    cin >> sec;

    system("CLS");

    for (int i = 0; i < numWords; i++) {
        GRand num;
        index[i] = num.i(60);
    }

    do {
        // Row 
        //cout << "j = " << j << endl;
        spaces[j] = word[index[j]].size();
        //cout << "Word = " << word[index[j]] << endl;
        //cout << "Spaces = " << spaces[j] << endl;
        whileSpaces[j] = 26 - spaces[j];
        k = whileSpaces[j];
        //cout << "whileSpaces[j] = " << whileSpaces[j] << endl;
        keep[j] = whileSpaces[j];
        words[j] = word[index[j]];
        switch (j % 3) {
        case 0:
            cout << "|----------------------------------------|" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|              " << word[index[j]];
            while (k != 0) {
                cout << " ";
                k--;
            }
            whileSpaces[j] = keep[j];
            cout << "|" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|----------------------------------------|" << flush;
            break;

        case 1:
            cout << "|----------------------------------------|" << endl;
            cout << "|                                        |" << endl;
            cout << "|              " << word[index[j]];
            while (k != 0) {
                cout << " ";
                k--;
            }
            whileSpaces[j] = keep[j];
            cout << "|" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|----------------------------------------|" << flush;
            break;

        case 2:
            cout << "|----------------------------------------|" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|              " << word[index[j]];
            while (k != 0) {
                cout << " ";
                k--;
            }
            whileSpaces[j] = keep[j];
            cout << "|" << endl;
            cout << "|----------------------------------------|" << flush;
            break;
        default:
            cout << "|----------------------------------------|" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|              " << word[index[j]];
            while (k != 0) {
                cout << " ";
                k--;
            }
            whileSpaces[j] = keep[j];
            cout << "|" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|                                        |" << endl;
            cout << "|----------------------------------------|" << flush;
            break;
        }
        Sleep(sec);

        system("CLS");
        j++;
        k = keep[j];
        if (j == numWords) {
            endGame = true;
        }
    } while (!endGame);

    for (int i = 1; i <= numWords; i++) {
        cout << "Write " << i << " word: ";
        cin >> answer[i];
        //cout << "answer[i] = " << answer[i] << endl;
        //cout << "words[i] = " << words[i - 1] << endl;
        if (answer[i] == words[i - 1]) {
            cout << "Yes" << endl;
            point++;
        }
        else {
            cout << "No" << endl;
        }
    }

    cout << "You get " << point << "/" << numWords << " points!" << endl;
}
