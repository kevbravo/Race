//Simple simulation of tortoise and hare race using arrays and pointers

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//First I declare the functions I used so the program can find them when executing main

void advanceHare(int* ptrHare);
void advanceTortoise(int* ptrTortoise);
void printPosition(int* ptrTortoise, int* ptrHare);

//The main function is always read first by the program and without it the program would not execute

int main(){

//Seeding a random number generator using a c library

	srand(time(NULL));

//starting position for elements in array
	int Tortoise = 0;
	int Hare = 0;

//using pointers to store the address of our variables
	int* ptrTortoise = &Tortoise;
	int* ptrHare = &Hare;

//While loop to keep the program running until either Tortoise or Hare win the race (reach end of array)
	while (Tortoise < 50 && Hare < 50){

//Calling the functions we declared previously
		advanceHare(ptrHare);
		advanceTortoise(ptrTortoise);

//If statements to account for index out of bounds
		if(*ptrTortoise < 0){

			*ptrTortoise = 0;
		}

		if (*ptrHare < 0){

			*ptrHare = 0;
		}

		if (*ptrTortoise > 50){

			*ptrTortoise = 50;
		}

		if (*ptrHare > 50){

			*ptrHare = 50;
		}

		if (*ptrHare == *ptrTortoise){

			*ptrTortoise = *ptrTortoise - 1;
		}

		printPosition(ptrTortoise, ptrHare);
	}

	if (*ptrTortoise == 50){

		printf("The tortoise wins the race\n");
	}

	else{

		printf("The hare wins the race\n");
	}
}

void advanceHare(int* ptrHare){

//Using the random number generator
	int Hare_Dice = (rand() % 10) + 1;
	
	int advance = 0;
	int* ptrAdvance = &advance;

//If statements to determine position
	if (Hare_Dice <= 3){

		*ptrAdvance = 2;
	}

	else if (Hare_Dice >= 4 && Hare_Dice < 7){

		*ptrAdvance = 3;
	}

	else if (Hare_Dice == 7){

		*ptrAdvance = 1;
	}

	else if (Hare_Dice == 8){

		*ptrAdvance = -2;
	}

	else{

		*ptrAdvance = -3;
	}

//Adding how many spaces moved to the current position
	*ptrHare += *ptrAdvance;
}

//Same as previous function
void advanceTortoise(int* ptrTortoise){

	int Tortoise_Dice = (rand() % 10) + 1;

	int advance = 0;
	int* ptrAdvance = &advance;

	if (Tortoise_Dice <= 6){

		*ptrAdvance = 1;
	}

	else if (Tortoise_Dice == 7){

		*ptrAdvance = 2;
	}

	else if (Tortoise_Dice == 8){

		*ptrAdvance = 3;
	}

	else{

		*ptrAdvance = 0;
	}

	*ptrTortoise += *ptrAdvance;
}

//Print function to display results
void printPosition(int* ptrTortoise, int* ptrHare){

	char Race[] = "                                                  |";

	Race[*ptrTortoise] = 'T';
	Race[*ptrHare] = 'H';

	printf("%s\n", Race);
}
