//***********
// Implementation file: player.cc
// Implementing player.h methods
// Hayden Ivatts
// 9-9-18
// HW 1
// Professor Skadady
// Contains the implementation of the player.h file. The purpose is to create a
// dice poker game that generates random dice rolls and ranks the rolls. The
// player with the highest ranked roll gets a point for that round. The player
// with the most amount of points after a specified amount of rounds wins.
//***********

#include "player.h"

Player::Player(void ) {
    //Precondition:
    // None.
    //Postcondition:
    //   Initializes the dice roll array to all 0's
    //   Initializes rank to 0
    //   Initializes player points to 0
    int diceArray[numDice] = {0, 0, 0, 0, 0};
    int rank = 0;
    int points = 0;

} // end Player(void)
  
void Player::clearRank(void) {
    //Precondition:
    // None.
    //Postcondition:
    // Sets rank back to 0
    
    int rank = 0;
    
} // end clearRank(void)

void Player::clearPoints(void) {
    //Precondition:
    // None.
    //Postcondition:
    // Sets points to 0
    
    int points = 0;
    
} // end clearPoints(void)

void Player::throwDice(void) {
    //Precondition:
    // None.
    //Postcondition:
    // Generates a random number as a dice roll and adds it to the array of 5
    // dice rolls.
    //Prints out what each roll is and then computes the rank of the player

    // Generates a random number to represent a dice roll 5 times and puts each
    // number in the correct arrray index
    for(int i = 0; i < numDice; i++) {
        diceArray[i] = Randomize(6);
        cout << "Die #" << i + 1 << " is a " << diceArray[i] << "\n";
    }
    computeRank();
    
} // end throwDice(void)

void Player::showRank(void) {
    //Precondition:
    // None.
    //Postcondition:
    //  Based on the calculated rank, a phrase is printed out to show how each
    //  player did that round.

    //Depending on the rank, the correct phrase describing the roll is produced
    switch(rank) {
    case 6 :
        cout << "Five of a Kind, 6 points.";
        break;
    case 5 :
        cout << "Four of a Kind, 5 points.";
        break;
    case 4 :
        cout << "Full House, 4 points.";
        break;
    case 3 :
        cout << "Three of a Kind, 3 points.";
        break;
    case 2 :
        cout << "Two Pairs, 2 points.";
        break;
    case 1 :
        cout << "One Pair, 1 point.";
        break;
    default :
        cout << "Nothing, 0 points";
    }
} // end showRank

int Player::getRank(void) {
    //Precondition:
    // None.
    //Postcondition:
    //  returns the current rank of the player.
    
    return rank;
  
} // end getRank(void)
  
int Player::getPoints( void ) {
    //Precondition:
    // None.
    //Postcondition:
    //  returns the current points of the player
    
    return points;
  
} // end getPoints(void)
 
void Player::addPoint(void) {
    //Precondition:
    // None.
    //Postcondition:
    //  Increments the current points by 1
    
    points++;
    
} // end addPoint(void)

void Player::computeRank(void) {
    //Precondition:
    // None.
    //Postcondition:
    // Computes and sets the rank of the diceArray
    
    int rank_calc[7] = {0,0,0,0,0,0}; // Keeps track of how many of each number is rolled

    // Scans diceArray for each value rolled and uses switch to add one to rank_calc array
    // each time a value is detected
    for(int i = 0; i < numDice; i++) {
        switch(diceArray[i]) {
        case 1 :
            rank_calc[1]++;
            break;
        case 2 :
            rank_calc[2]++;
            break;
        case 3 :
            rank_calc[3]++;
            break;
        case 4 :
            rank_calc[4]++;
            break;
        case 5 :
            rank_calc[5]++;
            break;
        case 6 :
            rank_calc[6]++;
            break;
        }
    }
    
    rank = 0;

    // Ranks each roll using if statements. Based on how many values were detected in rank_calc
    // rank is changed to correct number.
    for(int j = 0; j < 7; j++) {
       
        if(rank == 1 && rank_calc[j] == 2) {
            rank = 2;
        } else if(rank_calc[j] == 2) {
            rank = 1; 
        }
       
        if(rank == 1 && rank_calc[j] == 3) {
            rank = 4;
        } else if(rank_calc[j] == 3) {
            rank = 3;
        }
        
        if(rank_calc[j] == 4) {
            rank = 5;
        }

        if(rank_calc[j] == 5) {
            rank = 6;
        }
    }  
} // end computeRank(void)

/**********Randomize*****************************
 *Get a random number between 1 and range        *
 *************************************************/
int Randomize(int range)
{
    //Precondition:
    //  Enter the range of numbers the generator chooses from.
    //Postcondition:
    //  Get a random number between 1 and range

    return (int)(((double)rand()/((double)RAND_MAX + 1.0)) * (double)range) + 1;

} //Randomize

