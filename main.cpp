#include <iostream>
#include "Judge.h"
//#include "Player.h"

using namespace std;

int main()
{
    Judge judge;
    Player player1, player2;

    judge.init(player1, player2);

    while (not judge.is_finished)    
    {
        judge.get_players_move(player1);
        judge.get_players_move(player2);
        judge.print_board();
        judge.check_state();
    }

    return 0;
}
