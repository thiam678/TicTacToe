/*
 * Main.cpp
 *
 *  Created on: Sep 23, 2022
 *      Author: mccar
 */
#include <iostream>
using namespace std;
#include "TicTacToe.h"

int main(){
	
    // Create a new TicTacToe object named game
	TicTacToe game;
	// Display a welcome message for the players
    game.welcomePlayers();
     // Display the game board
	game.boardView();
	// Loop while there is no winner
	while(game.winCondition())
	{
		// Prompt the player whose turn it is to make a move and update the game board
    	game.playerTurn();
    	// Check if there is a winner
	    game.winCondition();
    }
    // Display the result of the game
    game.result();
   
    // Return 0 to indicate successful execution of the program
   return 0;
}


