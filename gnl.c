#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char	board[3][3];
const char	PLAYER = 'X';
const char	COMPUTER = 'O';

void	printWinner(char);

void	resetBoard()
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			board[i][j] = ' ';
			j++;
		}
		i++;
	}
}
void	printBoard()
{
	printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
	printf("\n---|---|---\n");
	printf(" %c  |  %c |  %c ", board[1][0], board[1][1], board [1][2]);
	printf("\n---|---|---\n");
	printf(" %c  |  %c |  %c ", board [2][0], board [2][1], board[2][2]);
	printf("\n");
}
int	checkFreeSpaces()
{
	int	freespaces;
	int	i;
	int	j;

	freespaces = 9;
	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			if (board[i][j] != ' ')
				freespaces--;
			j++;
		}
		i++;
	}
	return (freespaces);
}
void	playerMoves()
{
	int	x;
	int	y;

	x = -1;
	y = -1;

	while (x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] != ' ')
	{
		printf("Enter row #(1-3): ");
		scanf("%d", &x);
		x--;
		printf("Enter column #(1-3): ");
		scanf("%d", &y);
		y--;

		if (x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] != ' ')
			printf("Invalid move!\n");
		else
			board[x][y] = PLAYER;
			break;
	}
}
void	computerMoves()
{
	//create a seed based on current time to generate random moves
	srand(time(0));
	int x;
	int y;

	if (checkFreeSpaces() > 0)
	{
		while (board[x][y] != ' ')
		{
			x = rand() % 3;
			y = rand() % 3;
		}
		board[x][y] = COMPUTER;
	}
	else
		printWinner(' ');
}
char	checkWinner()
{
	//check rows
	int	i;

	i = 0;
	while (i < 3)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
			return (board[i][0]);
		i++;
	}
	//checl columns
	i = 0;
	while (i < 3)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return (board[0][i]);
		i++;
	}
	//check diagonals
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return (board[0][0]);
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return (board[0][2]);
	return (' ');
}

void	printWinner(char winner)
{
	if (winner == PLAYER)
		printf("YOU WIN!");
	else if (winner == COMPUTER)
		printf("YOU LOSE!!! :(");
	else
		printf("ITS A TIE");
}

int	main()
{
	char	winner;
	char	response;

	do
	{
		winner = ' ';
		response = ' ';
		resetBoard();
			while (winner == ' ' && checkFreeSpaces() != 0)
			{
				printBoard();
				playerMoves();
				winner = checkWinner();
				if (winner != ' ' || checkFreeSpaces() == 0)
					break;
			}
		printBoard();
		printWinner(winner);

		printf("\nWould you like to play again? (Y/N): ");
		scanf("%c");
		scanf("%c", &response);
		response = toupper(response);

	}while (response == 'Y');
	printf("Thanks for playing!");

	return (0);
}
