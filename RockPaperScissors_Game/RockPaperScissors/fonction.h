#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<windows.h>

#define TAILLE 10

typedef struct TYPE {
	bool data;
	char ID;
}Type;

typedef struct CHOICE {
	Type rock;
	Type paper;
	Type scissor;
}Choice;

void displayMainMenu();
void displayMainTitle();
void initChoice(Choice * RPS);
void choiceComputer(Choice * RPS);
char whichOne(Choice* RPS);
bool victory(Choice* player, Choice* computer);
void restart(int* ptPlayer, int* ptComputer);
void displayChoice(Choice* player, Choice* computer);
void displayParty(char message[], int *ptPlayer, int *ptComputer, int color);
void displayVictory(Choice* player, Choice* computer, int *ptPlayer, int *ptComputer);

void Color(int couleurDuTexte, int couleurDeFond);