#include"fonction.h"

int compteurPlayer = 0, compteurComputer = 0;
int* ptrCompteurPlayer = &compteurPlayer;
int* ptrCompteurComputeur = &compteurComputer;

int main(int argc, char* argv[]) {
	Choice Player;
	Choice Computer;
	char buttonKeyboard;

	Color(15, 0);
	displayMainMenu();
	initChoice(&Player);
	initChoice(&Computer);

	do
	{
		do
		{
			buttonKeyboard = (char)toupper(_getch());
		} while ((buttonKeyboard != 'R') && (buttonKeyboard != 'P') && (buttonKeyboard != 'S') && (buttonKeyboard != 'E') && (buttonKeyboard != 'X'));
		

		switch (buttonKeyboard)
		{
		case 'R':
			system("cls");
			displayMainTitle();
			Player.rock.data = true;
			choiceComputer(&Computer);
			displayChoice(&Player, &Computer);
			displayVictory(&Player, &Computer, ptrCompteurPlayer, ptrCompteurComputeur);
			break;
		case 'P':
			system("cls");
			displayMainTitle();
			Player.paper.data = true;
			choiceComputer(&Computer);
			displayChoice(&Player, &Computer);
			displayVictory(&Player, &Computer, ptrCompteurPlayer, ptrCompteurComputeur);
			break;
		case 'S':
			system("cls");
			displayMainTitle();
			Player.scissor.data = true;
			choiceComputer(&Computer);
			displayChoice(&Player, &Computer);
			displayVictory(&Player, &Computer, ptrCompteurPlayer, ptrCompteurComputeur);
			break;
		case 'E':
			restart(ptrCompteurPlayer, ptrCompteurComputeur);
			system("cls");
			displayMainMenu();
			break;
		}
		initChoice(&Player);
		initChoice(&Computer);
	} while ((buttonKeyboard != 'X'));
}