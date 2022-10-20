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
char getPlayerChar(CELL cell);
string getPlayerName(CELL cell);

int main()
{
    setConsoleWindow();


    bool isOver = false;
    GRID grid = {};

    CELL turn = CELL::PLAYER1;
    do {
        showGrid(grid);

        setTextColor(RESET);

        cout << "Current turn : " << getPlayerName(turn) << endl;

        setTextColor(RESET);

        int input;

        cout << "Choose a column to play on: (1-" << COLS << ") : ";
        cin >> input;

        // Prompt user for input and handle any possible invalid input.
        if (!(input > 0 and input <= COLS) or cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');

            cerr << endl << "Invalid input. Try again." << endl;
            continue;
        }

        // Arrays start with 0;
        input--;

        // Get the last available position to play on and check if the column is not full.
        int lastIndex = getLastIndex(grid, input);
        if (lastIndex < 1)
        {
            cerr << "This column is full. Choose a different one." << endl;
            continue;
        }

        // Update the grid with the newly-played position.
        grid[lastIndex - 1][input] = turn;

        // Update next player's turn.
        turn = turn == CELL::PLAYER1 ? CELL::PLAYER2 : CELL::PLAYER1;

    } while (!isOver);

    return EXIT_SUCCESS;
}

char getPlayerChar(CELL cell)
{
    switch (cell) {
        case CELL::BLANK:
            setTextColor(RESET);
            return '0';
        case CELL::PLAYER1:
            setTextColor(YELLOW);
            return '0';
        case CELL::PLAYER2:
            setTextColor(GREEN);
            return '0';
    }
}

string getPlayerName(CELL cell)
{
    switch (cell) {
        case CELL::PLAYER1:
            return "Player 1";
        case CELL::PLAYER2:
            return "Player 2";
    }
}

void showGrid(GRID grid)
{
    // Print column numbers.
    setTextColor(LIGHT_YELLOW);

    for (int i = 0; i < COLS; ++i) {
        cout << " " << i + 1 << "  ";
    }

    // Print the entire grid.
    setTextColor(RESET);

    cout << endl;

    for (int y = 0; y < ROWS; ++y)
    {
        for (int i = 0; i < COLS; ++i) {
            cout << "+---";
            if (i == COLS - 1)
            {
                cout << "+";
            }
        }

        cout << endl;

        for (int x = 0; x < COLS; ++x)
        {
            cout << "| " << getPlayerChar(grid[y][x]) << " ";
            if (x == COLS - 1)
            {
                cout << "|";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < COLS; ++i) {
        cout << "+---";
        if (i == COLS - 1)
        {
            cout << "+";
        }
    }

    cout << endl;
}

int getLastIndex(GRID grid, int indexCol)
{
    for(int x = 0; x < ROWS; ++x )
    {
        if(grid[x][indexCol] != CELL::BLANK)
        {
            return x;
        }
    }

    return ROWS;
}