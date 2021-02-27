#include"fonction.h"

void displayMainMenu() {
	displayMainTitle();
	printf("Rules are very easy\n");
	printf("Rock beats Scissor; Scissor cuts Paper; Paper recovers Rock\n");
	printf("Rock -> Scissor -> Paper -> Rock ...\n");
	printf("Press 'R' for Rock, 'P'for Paper or 'S' for Scissor to start playing");
}
void displayMainTitle() {
	char title[] = "*Welcome in the Rock Paper Scissor - Game*";
	for (int i = 0; i < strlen(title); i++)
	{
		printf("*");
	}
	printf("\n%s\n", title);
	for (int i = 0; i < strlen(title); i++)
	{
		printf("*");
	}
	printf("\n\n");
}

void initChoice(Choice * RPS) {
	RPS->rock.data = false;
	RPS->rock.ID = 'R';
	RPS->paper.data = false;
	RPS->paper.ID = 'P';
	RPS->scissor.data = false;
	RPS->scissor.ID = 'S';
	return;
}

void choiceComputer(Choice * RPS)
{
	srand((unsigned)time(NULL));
	int alea = rand() % 3 + 1;
	switch (alea)
	{
	case 1:
		RPS->rock.data = true;
		break;
	case 2:
		RPS->paper.data = true;
		break;
	case 3:
		RPS->scissor.data = true;
		break;
	}
}


char whichOne(Choice* RPS) {
	if (RPS->rock.data == true)
	{
		return RPS->rock.ID;
	}
	else if (RPS->paper.data == true)
	{
		return RPS->paper.ID;
	}
	else if (RPS->scissor.data == true)
	{
		return RPS->scissor.ID;
	}
	else 
	{
		return 'X';
	}
}

bool victory(Choice* player, Choice* computer) {
	bool returnVictory = false;
	if ((whichOne(player) != 'X') && (whichOne(computer) != 'X'))
	{
		if ((whichOne(player) == whichOne(computer)))
		{
			returnVictory = false;
		}
		if (whichOne(player) == 'R')
		{
			if (whichOne(computer) == 'S')
			{
				returnVictory = true;
			}
			else 
			{
				returnVictory = false;
			}
		}
		if (whichOne(player) == 'P')
		{
			if (whichOne(computer) == 'R')
			{
				returnVictory = true;
			}
			else
			{
				returnVictory = false;
			}
		}
		if (whichOne(player) == 'S')
		{
			if (whichOne(computer) == 'P')
			{
				returnVictory = true;
			}
			else
			{
				returnVictory = false;
			}
		}
	}
	return returnVictory;
}

void restart(int* ptPlayer, int* ptComputer) {
	*ptPlayer = 0;
	*ptComputer = 0;
}

void displayChoice(Choice* player, Choice* computer) {
	char wordChoicePlayer[TAILLE] = { 0 };
	char wordChoiceComputer[TAILLE] = { 0 };
	char rock[] = "Rock";
	char paper[] = "Paper";
	char scissor[] = "Scissor";
	switch (whichOne(player))
	{
	case 'R':
		strcat_s(wordChoicePlayer, TAILLE, rock);
		break;
	case 'P':
		strcat_s(wordChoicePlayer, TAILLE, paper);
		break;
	case 'S':
		strcat_s(wordChoicePlayer, TAILLE, scissor);
		break;
	}
	switch (whichOne(computer))
	{
	case 'R':
		strcat_s(wordChoiceComputer, TAILLE, rock);
		break;
	case 'P':
		strcat_s(wordChoiceComputer, TAILLE, paper);
		break;
	case 'S':
		strcat_s(wordChoiceComputer, TAILLE, scissor);
		break;
	}
	printf("You've choose %s and IA has choose %s\n\n", wordChoicePlayer, wordChoiceComputer);
}

void displayParty(char message[], int *ptPlayer, int *ptComputer, int color)
{
	int sizeText = strlen(message);
	for (int i = 0; i < (20-sizeText)/2; i++)
	{
		printf("-");
	}
	Color(color, 0);
	printf("%s", message);
	Color(15, 0);
	for (int i = 0; i < (20 - sizeText) / 2; i++)
	{
		printf("-");
	}
	printf("\n");


	for (int i = 0; i < (20 - 5) / 2; i++)
	{
		printf("-");
	}
	printf("Score");
	for (int i = 0; i < ((20 - 5) / 2)+1; i++)
	{
		printf("-");
	}
	printf("\n");


	for (int i = 0; i < (20 - 5) / 2; i++)
	{
		printf("-");
	}
	printf("%d - %d", *ptPlayer, *ptComputer);
	for (int i = 0; i < ((20 - 5) / 2) + 1; i++)
	{
		printf("-");
	}
	printf("\n");
}

void displayVictory(Choice* player, Choice* computer, int *ptPlayer, int *ptComputer)
{
	if (victory(player, computer) == true)
	{
		*ptPlayer += 1;
		displayParty("Victoire", ptPlayer, ptComputer, 10);
	}
	else
	{
		*ptComputer += 1;
		displayParty("Defaite-", ptPlayer, ptComputer, 12);
	}
	printf("\nPress 'R' for Rock, 'P'for Paper or 'S' for Scissor to continue\n");
	printf("Press 'E' for restart\n");
	printf("Press 'X' for quit\n");
}

void Color(int textColor, int backgroundColor)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, backgroundColor * 16 + textColor);
}