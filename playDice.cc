/***************************************************************************
 * playDice.cc
 * Author: CSCI 132 Instructor
 * Date: Spring 2018
 * Class: CSCI 132
 * Assignment: Homework 1
 * Purpose: To play the game, "DicePoker"
 * Input: User inputs number of rounds and whether or not to continue playing.
 * Output: Prompts user for number of rounds.  Outputs the results and winner 
 *         of each round and the winner of the game.  Prompts user on whether
 *         to continue playing.
 ***************************************************************************/
#include "player.h"

void playRound(Player &, int);    
void getRoundWinner(Player &, Player &);
void getGameWinner(Player, Player);

int main( void ) {
  char answer;           //Answer whether user wants to play
  int numRounds;         //Number of rounds in a game
  Player player1;        //First player
  Player player2;        //Second player

  cout << "Would you like to play a game (y/n)?" << endl;
  cin >> answer;
  cout << answer << endl;

  //Keep playing games as long as user answers y.
  while (answer == 'y' ) {

    //clear number of points for each player
    player1.clearPoints( );
    player2.clearPoints( );

    //Prompt user for number of rounds.  Play that many rounds.
    cout << "How many rounds (less than 10) would you like to play?" << endl;
    cin >> numRounds;
    cout << numRounds << endl;

    for (int i = 0; i < numRounds; i++ ) {
      cout << endl << "Round #" << i+1 << ":" << endl;
      playRound(player1, 1);
      playRound(player2, 2);
      getRoundWinner(player1, player2);
    } //end for each round

    //Compute winner and report who won.
    getGameWinner(player1, player2);

    //Ask user if he/she would like to play again.
    cout << "Would you like to play again (y/n)?" << endl;
    cin >> answer;
    cout << answer << endl;

  } // end while the user wants to play another round

    cout << "Thank you for playing Dice Poker!" << endl;

} //end main

/*****************************************************************
 * void playRound(Player &thisPlayer, int which)
 * Purpose: Play one round of DicePoker for a given player.
 * Input: None  
 * Output: (to standard output) result of dice throw and rank.
 * Precondition: none
 * Postcondition: rank of dice throw is stored in thisPlayer.rank
 * ****************************************************************/
void playRound(Player &thisPlayer, int which) {    
      thisPlayer.clearRank( );
      cout << "Player " << which << " throws: " << endl;
      thisPlayer.throwDice( );
      thisPlayer.showRank( );
      cout << endl;
} //end playRound( )

/*****************************************************************
 * void getRoundWinner(Player &player1, Player &player2)
 * Purpose: Computes the winner of a given round.
 * Output: (to standard out) Which player wins.
 * Precondition: Both players have played a round.
 * Postcondition: One point added to winner's total points.
 *****************************************************************/
void getRoundWinner(Player &player1, Player &player2) {

      if (player1.getRank( ) > player2.getRank( ) ) {
	cout << "Player 1 wins this round!" << endl;
	player1.addPoint( );
      } //player 1 winner 
      else if (player2.getRank( ) > player1.getRank( )) {
	cout << "Player 2 wins this round!" << endl;
	player2.addPoint( );
      } //player 2 winner
      else {
	cout << "This round is a tie!" << endl;
      } //end a tie round

      cout << endl;
} //end getRoundWinner( )

/*****************************************************************
 * void getGameWinner(Player player1, Player player2)
 * Purpose: Computes the winner of the game based on points.
 * Output: (to standard out) Which player wins (or if tie).
 * Precondition: Reqested number of rounds has been played
 *               for both players.
 * Postcondition: Winner is reported.
 ****************************************************************/
void getGameWinner(Player player1, Player player2) {
    if (player1.getPoints( ) > player2.getPoints( ) ) 
      cout << "Player 1 wins the game!" << endl;
    else if (player2.getPoints( ) > player1.getPoints( ) ) 
      cout << "Player 2 wins the game!" << endl;
    else 
      cout << "The game is a tie!" << endl;
    
} //end getGameWinner( )
