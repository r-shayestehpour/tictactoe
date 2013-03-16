#include <iostream>
#include "Player.h"

using namespace std;

class Judge
{
    public:
        //Attributes
        char board[3][3];
        bool is_finished;

        //Methods
        void get_players_move(Player);
        void init(Player, Player);
        void print_board();
        void check_state();        
};

void Judge :: init(Player player1, Player player2)
{
    //initializes the components @ start of the game
    player1.color = 'x';
    player2.color = 'o';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    is_finished = false;
}

void Judge :: get_players_move(Player player)
{
    //gets Player player's move and updates board
    board[player.best_move[0]][player.best_move[1]] = player.color;
}

void Judge :: print_board()
{
    //prints the board
    for (int i = 0; i < 3; i++)
    {
        cout << board[i][0] << " | " << board[i][1] << " | " <<
            board[i][2] << endl;
        if (i < 2) cout << "-------------" << endl;
    }
}

void Judge :: check_state()
{
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] == board[i][2] and board[i][0] != ' ')
        {
            cout << "winner is: player " << board[i][0] << endl;
            is_finished = true;
            return;
        }
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] == board[2][i] and board[1][i] != ' ')
        {
            cout << "winner is: player " << board[0][i] << endl;
            is_finished = true;
            return;
        }
    if (board[0][0] == board[1][1] == board[2][2] and board[0][0] != ' ')
    {
        cout << "winner is: player " << board[0][0] << endl;
        is_finished = true;
        return;
    }
    if (board[0][2] != ' ' and board[0][2] == board[1][1] == board[2][0])
    {
        cout << "winner is: player " << board[1][1] << endl;
        is_finished = true;
        return;
    }
}
