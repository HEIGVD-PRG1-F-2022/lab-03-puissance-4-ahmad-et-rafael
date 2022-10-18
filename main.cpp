#include <iostream>
#include <iomanip>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

enum CELL {
    BLANK, PLAYER1, PLAYER2
};
int grid[ROWS][COLS] = {};


void showGrid();

int main() {
    grid[0][0] = CELL::PLAYER1;
    grid[6][5] = CELL::PLAYER2;

    showGrid();

bool isOver = false;

    do {
        int input;

        cout << "Enter a number between 1 and " << COLS << " : ";
        cin >> input;
        if( !(input > 0 and input < COLS) or cin.fail()){
            cin.clear();
            cout << "Entree invalide "<< endl;
            continue;

        }





    } while (!isOver);




    return 0;
}
string getPlayerName(CELL cell){
    switch (cell) {
        case 0:
            return "0";
        case 1:
            return "PLAYER1";
            case 2:
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
