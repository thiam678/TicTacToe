/*
 * TicTacToe.h
 *
 *  Created on: Sep 23, 2022
 *      Author: mccar
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_
#include <iostream>
using namespace std;

class TicTacToe {
private:
	// Initialize the game board as a 3x3 char array with numbers indicating available moves
	 char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	 int num,i,j;
	 char turn;
	 bool draw;

public:
	// Constructor - initialize the starting values for the game
	 TicTacToe(){
	   this->turn='X';
	   this->draw=false;
	   this->num=0;
	   this->i=0;
	   this->j=0;
	 }

    // Display a welcome message for the players
    void welcomePlayers(){
    	 cout<<"\n\t\t===================================\n";
    	 cout<<"\n\t\t          TIC TAC TOE GAME           \n";
    	 cout<<"\n\t\t===================================\n";
    	 cout<<"\n\t\tPLAYER 1 (X) \n\t\tPLAYER 2 (0)\n\n";

    }
    // Display the current state of the game board
    void boardView(){
    	cout<<"\t\t     |      |     \n";
    	cout<<"\t\t  "<<arr[0][0]<<"  |   "<<arr[0][1]<<"  |  "<<arr[0][2]<<"  \n";
    	cout<<"\t\t_____|______|_____\n";
    	cout<<"\t\t     |      |     \n";
    	cout<<"\t\t  "<<arr[1][0]<<"  |   "<<arr[1][1]<<"  |  "<<arr[1][2]<<"  \n";
    	cout<<"\t\t_____|______|_____\n";
    	cout<<"\t\t     |      |     \n";
    	cout<<"\t\t  "<<arr[2][0]<<"  |   "<<arr[2][1]<<"  |  "<<arr[2][2]<<"  \n";
    	cout<<"\t\t     |      |     \n";
    }
    // Prompt the player whose turn it is to enter a move and update the game board accordingly
    void playerTurn(){
    	if(turn=='X')
    	{
    	cout<<"\n\t\tPLAYER 1 (X) TURN: ";
    	cin>>num;
        }
    	if(turn=='O')
    	{
    	cout<<"\n\t\tPLAYER 2 (O) TURN: ";
    	cin>>num;
        }
    	switch(num)
    	{
    		case 1:i=0;j=0;
    		break;
    		case 2:i=0;j=1;
    		break;
    		case 3:i=0;j=2;
    		break;
    		case 4:i=1;j=0;
    		break;
    		case 5:i=1;j=1;
    		break;
    		case 6:i=1;j=2;
    		break;
    		case 7:i=2;j=0;
    		break;
    		case 8:i=2;j=1;
    		break;
    		case 9:i=2;j=2;
    		break;
    		default:cout<<" Invalid number.";
    		break;
    	}
    	if(turn=='X'&& arr[i][j]!='X'&& arr[i][j]!='O')
    	{
    		arr[i][j]='X';
    		turn='O';
    	}
    	else if(turn=='O'&& arr[i][j]!='X' && arr[i][j]!='O')
    	{
    		arr[i][j]='O';
    		turn='X';
    	}
    	else
    	{
    	cout<<"\n\t\t INVALID MOVE!! Please Try Again.\n\n";
    	playerTurn();
        }
        boardView();
    }
    // Check the game board for a win condition and return true if there is a win, false otherwise
    bool winCondition(){
    	for( i=0;i<3;i++)//winning
    		if((arr[i][0]==arr[i][1]&& arr[i][0]==arr[i][2]) || (arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i]))
    		{
    			return false;
    		}
    		if((arr[0][0]==arr[1][1]&& arr[0][0]==arr[2][2])||(arr[0][2]==arr[1][1]&& arr[0][2]==arr[2][0]) )
    		return false;

    		for( i=0;i<3;i++) //when one box remains unfilled
    		for( j=0;j<3;j++)
    		if(arr[i][j]!='X' && arr[i][j]!='O')
    		return true;
    		draw=true; //game draw
    		return false;
    }
	void result(){
		// If player X won and the game was not a draw, print that player 2 (O) won
		if(turn=='X'&& draw==false)
		    cout<<"\n\t\tPLAYER 2 (O) WON THE GAME!!!.\n";
		// If player O won and the game was not a draw, print that player 1 (X) won
		else if(turn=='O'&& draw==false)
		    cout<<"\n\t\tPLAYER 1 (X) WON THE GAME!!!.\n";
		    // If the game was a draw, print that the game was a draw
		else
		    cout<<" \n\t\tGAME DRAW\n";
	}


};

#endif /* TICTACTOE_H_ */
