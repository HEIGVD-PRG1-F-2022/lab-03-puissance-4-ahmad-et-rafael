#include <iostream>
#include <iomanip>
#include <windows.h>


using namespace std;

const int ROWS = 6;
const int COLS = 7;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

enum CELL {
    BLANK, PLAYER1, PLAYER2
};
int grid[ROWS][COLS] = {};
CELL turn = CELL::PLAYER1;

void showGrid();
int getLastIndex(int grid[ROWS][COLS], int indexCol);
string getPlayerName(CELL cell);


int main() {

    //grid[0][0] = CELL::PLAYER1;
    //grid[6][5] = CELL::PLAYER2;
    //grid[1][3] = CELL::PLAYER2;

    bool isOver = false;

    do {

        showGrid();

        cout << "Player turn : " << getPlayerName(turn) << endl;
        int input;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "Enter a number between 1 and " << COLS << " : ";
        cin >> input;

        if (!(input > 0 and input <= COLS) or cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            //cout << " " << endl;
            cerr << endl << "Entree invalide ";
            continue;
        }

       int lastIndex = getLastIndex(grid,input - 1);

        grid[input - 1][lastIndex - 1] = turn;

        turn = turn == CELL::PLAYER1 ? CELL::PLAYER2 : CELL::PLAYER1;

    } while (!isOver);


    return 0;
}

string getPlayerName(CELL cell) {


    switch (cell) {
        case 0:
            SetConsoleTextAttribute(hConsole, 7);
            return "0";

        case 1:

            SetConsoleTextAttribute(hConsole, 14);
            return "PLAYER1";

        case 2:
            SetConsoleTextAttribute(hConsole, 10);
            return "PLAYER2";

    }

}

void showGrid() {

    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLS; ++x) {

            cout << setw(7) << getPlayerName(CELL(grid[x][y])) << " ";
        }
        cout << endl;
    }
}

int getLastIndex(int grid[ROWS][COLS], int indexCol){

    for(int x=0; x < ROWS; ++x ){

        if(grid[indexCol][x] != CELL::BLANK)
            return x;
    }

    return ROWS;
}