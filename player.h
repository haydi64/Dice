//*******************************************************
//SPECIFICATION FILE (player.h)
//This file gives the specification for the Player class
//Author: Hayden Ivatts
//Class: CSCI 132
//HW1
// 9-9-18
//*******************************************************
#include <iostream>
#include <cstdlib>

using namespace std;

const int numDice = 5;

int Randomize(int);
//Precondition:
//  Enter the range of numbers the generator chooses from.
//Postcondition:
//  Get a random number between 1 and range


class Player {
public:
  Player( );
  //Precondition:
    // None.
    //Postcondition:
    //   Initializes the dice roll array to all 0's
    //   Initializes rank to 0
    //   Initializes player points to 0
  
  void clearRank(void);
   //Precondition:
    // None.
    //Postcondition:
    // Sets rank back to 0
  
  void clearPoints(void);
  //Precondition:
    // None.
    //Postcondition:
    // Sets points to 0
  
  void throwDice(void);
  //Precondition:
    // None.
    //Postcondition:
    // Generates a random number as a dice roll and adds it to the array of 5
    // dice rolls.
    //Prints out what each roll is and then computes the rank of the player
  
  void showRank(void);
  //Precondition:
    // None.
    //Postcondition:
    //  Based on the calculated rank, a phrase is printed out to show how each
    //  player did that round.
  
  int getRank(void);
   //Precondition:
    // None.
    //Postcondition:
    //  returns the current rank of the player.
  int getPoints( void );
   //Precondition:
    // None.
    //Postcondition:
    //  returns the current points of the player
  void addPoint(void);
  //Precondition:
    // None.
    //Postcondition:
    //  Increments the current points by 1
  
private:
  void computeRank(void);
  //Precondition:
    // None.
    //Postcondition:
    // Computes and sets the rank of the diceArray
  
  int diceArray[numDice]; //Keeps track of the value of each dice in a roll
  int rank; //Keeps track of the current roll rank
  int points; //Holds the total points of a player for each game
};
