#include <iostream>
using namespace std;

// Initialize the game board with empty spaces
char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

// Function to print the game board
void print_board() {
    cout << "-------------" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |" << endl;
        cout << "-------------" << endl;
    }
}

// Function to check if the game is over
bool game_over() {
    // Check for a winner
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;

    // Check for a tie game
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Function to get user input for their move
void get_move(int &row, int &col) {
    do {
        cout << "Enter a row and column for your move (e.g. 1 2): ";
        cin >> row >> col;
        row--;
        col--;
    } while(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
}

// Function to play the game
void play_game() {
    char player1 = 'X';
    char player2 = 'O';
    bool player1_turn = true;

    // Play the game until it is over
    while(!game_over()) {
        // Print the game board
        print_board();

        // Get the player's move
        int row, col;
        get_move(row, col);

        // Update the game board with the player's move
        if(player1_turn)
            board[row][col] = player1;
        else
            board[row][col] = player2;

        // Switch to the other player's turn
        player1_turn = !player1_turn;
    }

    // Print the final game board and winner/tie message
    print_board();
    if(game_over())
        cout << "Game over. ";
    if(player1_turn)
        cout << "Player 2 wins!" << endl;
    else
        cout << "Player 1 wins!" << endl;
}

int main() {
    play_game();
    return 0;
}
