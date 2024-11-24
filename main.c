/*
 ============================================================================
 Name        : EHausThreeNPlusOne.c
 Author      : Ethan Haus
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int computeNextValue(int input); //plugs input in to algorithm
int computeSequenceLength(int input); // determines how many times the algorithm needs to run
int computeMaxSequenceLength(int input, int input2); //keeps track of sequence of every number in range, keeps greatest
int score;
int score2;

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Enter output file data name:\n");
	char fileName [BUFSIZ];
	fgets(fileName,BUFSIZ,stdin);
	int length = strlen(fileName);
	fileName[length-1] = '\0';
	FILE *ftpr = fopen(fileName,"w");
	char numericInput [BUFSIZ];
	char numericInput2 [BUFSIZ];
	int yes;
	do{

		fgets(numericInput,BUFSIZ,stdin);

		if(numericInput[0] != '\n'){
			score = atoi(numericInput);

			fgets(numericInput2,BUFSIZ,stdin);
			score2 = atoi(numericInput2);
			yes = computeMaxSequenceLength(score,score2);
			fprintf(ftpr,"%d\t%d\t%d\n",score,score2,yes);
		}
	}while(numericInput[0] != '\n');

	fclose(ftpr);
	printf("Complete\n");
	return EXIT_SUCCESS;
}
int computeNextValue(int input){ //plugs input in to algorithm


	if(input % 2 == 0){
		input = input / 2;
	}
	else{
		input = (3*input) + 1;
	}


	return input;
}


int computeSequenceLength(int input){ // determines how many times the algorithm needs to run
	int counter = 0;
	while(input != 1){
		input = computeNextValue(input);
		counter++;
	}

	counter = counter +1;
	return counter;
}
int computeMaxSequenceLength(int input,int input2){ //keeps track of sequence of every number in range, keeps greatest
	int greatestResult;
	for(int i = input;i<=input2;i++){
		int result = computeSequenceLength(i);

		if(result > greatestResult){
			greatestResult = result;
		}

	}
	return greatestResult;
}


