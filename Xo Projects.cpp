#include <iostream>
using namespace std;

void get_step(char templete[3][3], int x, int y, char player) {
    templete[x][y] = player;
}

void display_Temp(char templete[3][3]) {
    cout << "  0   1   2\n";
    cout << "0 " << templete[0][0] << " | " << templete[0][1] << " | " << templete[0][2] << "\n";
    cout << " ---|---|---\n";
    cout << "1 " << templete[1][0] << " | " << templete[1][1] << " | " << templete[1][2] << "\n";
    cout << " ---|---|---\n";
    cout << "2 " << templete[2][0] << " | " << templete[2][1] << " | " << templete[2][2] << "\n";
}

int main() {
    char templete[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    display_Temp(templete);

    int steps = 0; // Tracks the total number of moves
    while (true) {
        int x, y;

        // Player X  turn
        cout << "Enter the row and column of X" << endl;
        cout << "X: ";
        cin >> x;
        cout << "Y: ";
        cin >> y;
        get_step(templete, x, y, 'X');
        display_Temp(templete);
        steps++;

        // Check if Player X wins
        if ((templete[0][0] == 'X' && templete[1][1] == 'X' && templete[2][2] == 'X') || // LtR Diagonal
            (templete[0][2] == 'X' && templete[1][1] == 'X' && templete[2][0] == 'X') || // RtL Diagonal
            (templete[0][0] == 'X' && templete[1][0] == 'X' && templete[2][0] == 'X') || // Left Column
            (templete[0][1] == 'X' && templete[1][1] == 'X' && templete[2][1] == 'X') || // Middle Column
            (templete[0][2] == 'X' && templete[1][2] == 'X' && templete[2][2] == 'X') || // Right Column
            (templete[0][0] == 'X' && templete[0][1] == 'X' && templete[0][2] == 'X') || // Top Row
            (templete[1][0] == 'X' && templete[1][1] == 'X' && templete[1][2] == 'X') || // Middle Row
            (templete[2][0] == 'X' && templete[2][1] == 'X' && templete[2][2] == 'X')) { // Bottom Row
            cout << "Player X is Winning !!\n";
            break;
        }

        if (steps == 9) { // Check for a draw
            cout << "Sorry, No One Is Winning.\n";
            break;
        }

        // Player O's turn
        cout << "Enter the row and column of O" << endl;
        cout << "X: ";
        cin >> x;
        cout << "Y: ";
        cin >> y;
        get_step(templete, x, y, 'O');
        display_Temp(templete);
        steps++;

        // Check if Player O wins
        if ((templete[0][0] == 'O' && templete[1][1] == 'O' && templete[2][2] == 'O') || // LtR Diagonal
            (templete[0][2] == 'O' && templete[1][1] == 'O' && templete[2][0] == 'O') || // RtL Diagonal
            (templete[0][0] == 'O' && templete[1][0] == 'O' && templete[2][0] == 'O') || // Left Column
            (templete[0][1] == 'O' && templete[1][1] == 'O' && templete[2][1] == 'O') || // Middle Column
            (templete[0][2] == 'O' && templete[1][2] == 'O' && templete[2][2] == 'O') || // Right Column
            (templete[0][0] == 'O' && templete[0][1] == 'O' && templete[0][2] == 'O') || // Top Row
            (templete[1][0] == 'O' && templete[1][1] == 'O' && templete[1][2] == 'O') || // Middle Row
            (templete[2][0] == 'O' && templete[2][1] == 'O' && templete[2][2] == 'O')) { // Bottom Row
            cout << "Player O is Winning !!\n";
            break;
        }

        if (steps == 9) {
            cout << "Sorry, No One Is Winning.\n";
            break;
        }
    }

    return 0;
}
