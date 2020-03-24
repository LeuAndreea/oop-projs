#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int arr[100];
	int length;
} vector;

/*Check if the command introduced by the user is valid
IN: command
OUT: true or false
*/
bool ValidCommand(int command) {
	if (command < 0 || command>2)
		return false;
	return true;
}


/*Check if the element for the sequence introduced by the user is valid
IN: element
OUT: true or false
*/
bool ValidElement(int elem) {
	if (elem < -1)
		return false;
	return true;

}

/*Checks if a number is prime.
IN: number
OUT: true if it is prime, false otherwise*/
bool IsPrime(int x) {
	if (x <= 1)
		return false;
	if (x == 2)
		return true;
	if (x % 2 == 0)
		return false;
	
	int div = 3;
	while (div*div <= x) {
		if (x%div == 0)
			return false;
		div += 2;
	}
	return true;
	
}

/*Reads an integer 
IN: a message regarding the input we want
OUT:an integer number*/
int ReadInteger(char *message){
	int nb;
	printf("%s\n",message);
	scanf("%d", &nb);
	
	return nb;
}



/*Reads an array of integers
IN: -
OUT: an array of numbers
*/

vector ReadSequence() {
	int x;
	vector v;

	v.length = 0;

	int i = -1;
	do {
		x = ReadInteger("Please introduce an integer number:");
		if (!ValidElement(x)) {
			printf("Invalid number!It must be greater than -1.");
		}
		else {
			i += 1;
			v.arr[i] = x;
		}
	} while (v.arr[i] != 0 && v.arr[i] != -1);
	v.length = i + 1;

	return v;
}

/*Prints the menu for the user
IN: -
OUT: -
*/
void PrintMenu() {
	printf("0.Exit\n");
	printf("1.Read sequences of positive integers , determine the max elem of each sequence\n");
	printf("and the max elems of all sequences\n");
	printf("2.Given a vector of numbers, find the longest contiguous subsequence such that \n");
	printf("all elements are in a given interval\n ");
	printf("Generate all prime numbers smaller than a given number.\n");
}

/*Prints fruther instructions for option 1
IN-
OUT-
*/
void PrintInstructions1() {
	printf("The sequences must contain positive integers.\n");
	printf("If you want to start reading a new sequence, introduce 0.\n");
	printf("If you want to stop reading sequences, introduce -1.\n");
}

/*Prints fruther instructions for option 1
IN-
OUT-
*/
void PrintInstructions2() {
	printf("When you want to stop reading the sequence, press 0.\n");
	printf("Please make sure you give the interval in the right format!");
}

void PrintInstructions3() {
	printf("Please introduce a natural number greater than 1!\n");
}


/*Print a sequence of numbers
IN: a vector
OUT - 
*/
void PrintSequence(vector v) {
	for (int i = 0; i < v.length; i++)
		printf("%d  ", v.arr[i]);
	printf("\n");
}

/*Print a subsequence of numbers, the start and finish position are sure to be right.
IN: a vector and the start and finish positions of the subsequence
OUT -
*/
void PrintSubSequence(vector v, int st, int fnsh) {
	for (int i = st; i <= fnsh; i++)
		printf("%d  ", v.arr[i]);
}




/*Finds the maxim element of a vector
IN: a vector
OUT: the max elem of a vector
*/
int GetMax(vector v) {
	int maxElem = 0;
	for (int i = 0; i < v.length-1; i++) 
		if (v.arr[i] > maxElem)
			maxElem = v.arr[i];
	
	return maxElem;
}


/*Adds the maxim of the last read sequence to the vector of all locals maxims
IN: the sequence of local maxims,current sequence
OUT: the sequence of locam maxims with an elem added
*/
void GetNextElem(vector *localMaxElems, vector v) {
	int newElement;
	newElement = GetMax(v);
	localMaxElems->arr[localMaxElems->length] = newElement;
	localMaxElems->length += 1;

	
}


/*Gets the sequences one by one and immediately finds the max element
IN: -
OUT: the sequence of local max elems and the global max
*/
void GetInfo(vector *localMaxElems, int *globalMax) {
	vector v = ReadSequence();
	GetNextElem(localMaxElems, v);
	//checks when it should stop reading vectors
	while (v.arr[v.length - 1] != -1) {
		v = ReadSequence(); 
		GetNextElem(localMaxElems, v);	
	}
	
	*globalMax = GetMax(*localMaxElems);
}


void FindMaxSequence(vector v, int a, int b, int *st, int *fnsh) {
	int lmax = 0, i = 0, l, j;
	while (i <= v.length) {
		l = 0;
		j = i;
		while (v.arr[j] >= a && v.arr[j] <= b && j != v.length) {
			l += 1;
			j += 1;
		}
		if (l > lmax) {
			lmax = l;
			*st =i;
			*fnsh = j-1;
		}
		i = j + 1;
	}

}
		
vector GeneratePrimeNumbers(int n) {
	vector v;
	v.length = 0;


	v.arr[0] = 2;
	int i = 1;
	
	int x = 3;
	while (x < n) {
		if (IsPrime(x)) {
			v.arr[i] = x;
			i += 1;
		}
		x += 2;
	}
	v.length = i;
	
	return v;
}


int main() {
	
	int command = -1;
	while (1) {
		PrintMenu();
		command = ReadInteger("Give command:");

		switch (command) {
			case 1: 
				PrintInstructions1();
				
				vector localMaxElems;
				localMaxElems.length = 0;
				int globalMax=0;

				GetInfo(&localMaxElems, &globalMax);
				
				printf("The maxim elems of each sequence were: ");
				PrintSequence(localMaxElems);
				printf("The maxim elem of all sequences was %d\n", globalMax);

				break;
			case 2: 
				PrintInstructions2();

				int a = ReadInteger("Give the left limit of interval:\n"),
					b = ReadInteger("Give the right limit of interval:\n"),
					st = 0,
					fnsh = 0;
				vector v = ReadSequence();

				while (a > b) {
					printf("Invalid interval, try again!");
					a = ReadInteger("Give the left limit of interval:\n");
					b = ReadInteger("Give the right limit of interval:\n");
				}
				
				FindMaxSequence(v, a, b, &st, &fnsh);

				printf("Your subsequence is: ");
				PrintSubSequence(v, st, fnsh);
				printf("\n");
			
				break;
			case 3:
				PrintInstructions3();
				
				int n = ReadInteger("Give the value: ");
				while (n <= 1)
					n = ReadInteger("Please itroduce a valid value!");
				
				vector w = GeneratePrimeNumbers(n);	
				printf("The prime numbers less than %d are: ",n);
				PrintSequence(w);
		
				break;
		}
	}
	
	system("pause");
	return 0;
}