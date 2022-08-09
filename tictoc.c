#include <stdio.h>

/**********************************
     DEFINITION OF FUNCTIONS
**********************************/
int checkwin(char square[]);
void board(char square[]);
void Decider(int player, char square[]);

int main()
{
	// player IS A COUNTER FOR PLAYER TURNING
	int player = 1;

	// FOR BUILD THE BOARD
	char square[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

	// PLAY GAME
	Decider(player, square);

	// FOR REPEATING GAME WITH USER INPUT
	player = 1;
	for (int i = 0; i < 10; ++i)
		square[i] = ' ';

	printf("Press 1 if you want to start a new game. Otherwise press 2.\n");
	int finish;
	scanf("%i", &finish);
	
	if (finish == 1)
		main();
	
	return 0;
}

/*********************************************
	FUNCTION TO FILL THE GAME BOARD
**********************************************/

void Decider(int player, char square[])
{

	// rc IS A CHECKER FOR VALID INPUT(IT SHOULD BE INTEGER)
	// i IS FOR winCheck RESULT 
	// choice IS FOR USER INPUT
	int i , rc, choice;
	char mark;

	printf("\n\t Tic-Tac-Toe\n\n");
	
	do
	{
		board(square);
		// IT IS FOR MAKE NEW TURN
		player = (player%2)?1:2;
		mark = (player == 1) ? 'X' : 'O';

		printf("Player %c's turn : \n", mark);
		printf("Plaese choose a number between 1 to 9. \n");
		
		int choice;

		//CHECK VALID INPUT
		while((rc = scanf("%i", &choice)) == 0)
		{
			scanf("%*[^\n]");
	 		printf("Invalid input! \n");
	 		printf("Player %c's turn : \n", mark);
			printf("Plaese choose a number between 1 to 9. \n");
		}

		//FILL THE BOARD WITH USER INPUT
		if (choice == 1 && square[1] == ' ')
			square[1] = mark;
		else if (choice == 2 && square[2] == ' ')
			square[2] = mark;
		else if (choice == 3 && square[3] == ' ')
			square[3] = mark;
		else if (choice == 4 && square[4] == ' ')
			square[4] = mark;
		else if (choice == 5 && square[5] == ' ')
			square[5] = mark;
		else if (choice == 6 && square[6] == ' ')
			square[6] = mark;
		else if (choice == 7 && square[7] == ' ')
			square[7] = mark;
		else if (choice == 8 && square[8] == ' ')
			square[8] = mark;
		else if (choice == 9 && square[9] == ' ')
			square[9] = mark;
		
		//REPEAT USER TURN IF SHE/HE PRESS INVALID UNPUT
		else
		{
			printf("\nInvalid Move!\n");
			player--;
		}

		i = checkwin(square);
		player++;

	}while(i == -1);

	board(square);

	if(i == 1)
	{
		printf("Congratulations! \n");
		printf("Player %c has won the game.\n\n", mark);
	}

	else
	{
		printf("The game is over! \n");
		printf("No one has won the game.\n\n");
	}
}


/*********************************************
	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin(char square[])
{
	if (square[1] == square[2] && square[2] == square[3] && square[2] != ' ')
		return 1;
	else if (square[4] == square[5] && square[5] == square[6] && square[5] != ' ')
		return 1;
	else if (square[7] == square[8] && square[8] == square[9] && square[8] != ' ')
		return 1;
	else if (square[1] == square[4] && square[4] == square[7] && square[4] != ' ')
		return 1;
	else if (square[2] == square[5] && square[5] == square[8] && square[5] != ' ')
		return 1;
	else if (square[3] == square[6] && square[6] == square[9] && square[6] != ' ')
		return 1;
	else if (square[1] == square[5] && square[5] == square[9] && square[5] != ' ')
		return 1;
	else if (square[3] == square[5] && square[5] == square[7] && square[5] != ' ')
		return 1;
	else if (square[1] != ' ' && square[2] != ' ' && square[3] != ' ' && 
			 square[4] != ' ' && square[5] != ' ' && square[6] != ' ' && 
			 square[7] != ' ' && square[8] != ' ' && square[9] != ' ')
		return 0;
	else
		return -1;
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board(char square[])
{

	printf("\t     |     |     \n"
		   "\t  %c  |  %c  |  %c  \n"
		   "\t_____|_____|_____\n"
		   "\t     |     |     \n"
		   "\t  %c  |  %c  |  %c  \n"
		   "\t_____|_____|_____\n"
		   "\t     |     |     \n"
		   "\t  %c  |  %c  |  %c  \n"
		   "\t     |     |     \n\n"
		   , square[1], square[2], square[3]
		   , square[4], square[5], square[6]
		   , square[7], square[8], square[9]);
}

/*******************************************************************
				END OF PROJECT
********************************************************************/
