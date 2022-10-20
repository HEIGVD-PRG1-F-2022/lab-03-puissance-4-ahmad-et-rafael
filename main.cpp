#include <iostream>
#include <iomanip>
#include <limits>
#include "display.h"

const int ROWS = 6;
const int COLS = 7;

enum CELL {
    BLANK,
    PLAYER1,
    PLAYER2
};

typedef CELL GRID[ROWS][COLS];

using namespace std;

void showGrid(GRID grid);
int getLastIndex(GRID grid, int indexCol);
char getPlayerName(CELL cell);


int main()
{
    bool isOver = false;
    GRID grid = {};

    CELL turn = CELL::PLAYER1;

    do {
        showGrid(grid);

        setTextColor(RESET);

        cout << "Player turn : " << getPlayerName(turn) << endl;

        setTextColor(RESET);

        int input;

        cout << "Choose a column to play on: (1-" << COLS << ") : ";
        cin >> input;

        if (!(input > 0 and input <= COLS) or cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');

            cerr << endl << "Invalid input. Try again." << endl;
            continue;
        }

       int lastIndex = getLastIndex(grid, input - 1);

        grid[input - 1][lastIndex - 1] = turn;

        turn = turn == CELL::PLAYER1 ? CELL::PLAYER2 : CELL::PLAYER1;

    } while (!isOver);


    return EXIT_SUCCESS;
}

char getPlayerName(CELL cell)
{
    switch (cell) {
        case CELL::BLANK:
            setTextColor(WHITE);
            return '0';
        case CELL::PLAYER1:
            setTextColor(YELLOW);
            return '0';
        case CELL::PLAYER2:
            setTextColor(GREEN);
            return '0';
    }
}

void showGrid(GRID grid)
{
    for (int y = 0; y < ROWS; ++y)
    {
        for (int x = 0; x < COLS; ++x)
        {
            cout << getPlayerName(grid[x][y]) << " ";
        }
        cout << endl;
    }
}

int getLastIndex(GRID grid, int indexCol)
{
    for(int x = 0; x < ROWS; ++x )
    {
        if(grid[indexCol][x] != CELL::BLANK)
        {
            return x;
        }
    }

    return ROWS;
}