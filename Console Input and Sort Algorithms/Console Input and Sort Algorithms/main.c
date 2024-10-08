#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main() {
	int size = GetArraySize();
	int* unsortArray = (int*)malloc(size * sizeof(int));
	if (unsortArray == NULL) {
		printf("Memory Allocation failed");
		return -1;
	}

	GetIntegerArray(size, unsortArray);
	PrintArray(unsortArray, size);

	printf("Using Sort Algorithm to sort this Aray...\n");

	BubbleSort(unsortArray, size);
	PrintArray(unsortArray, size);

	free(unsortArray);
	return 0;
}

void PrintArray(int _arr[], int _size) {
	printf("The Array consists of following numbers: ");
	//print Input Array
	for (int i = 0; i < _size; i++)
	{
		printf("%i ", _arr[i]);
	}
	printf("\n");
}

void GetIntegerArray(int _size, int* _arr) {

	//Set memory space for user Input
	char input[1000]; //1KB

	printf("Now, please insert %i numbers for the array, each divided by space\n", _size);

	//Get User Input as Array of chars
	while (fgets(input, sizeof(input), stdin) == NULL) {
		printf("Invalid Input\n");
		while (getchar() != '\n'); // Clears Input buffer
	}

	TranslateStringToInt(input, _size, _arr);

}

int GetArraySize() {
	int size;
	printf("Please enter a size for the integer Array: ");
	while (scanf("%i", &size) != 1 || size <= 0) {
		printf("your Input was invalid, probably due to one of the following Reasons:\n");
		printf("1. Your Input was not of type Integer\n");
		printf("2. Your Input was less or equal to 0\n");
		printf("Plase now enter a Number which sets the size for your Array\n");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	printf("Your array will consist of %i units\n", size);
	return size;
}

void TranslateStringToInt(char _inputArr[], int _size, int* _arr) {
	char* readSection = strtok(_inputArr, " ");  //strok reads the content of input until it finds space
	int arrayIndex = 0;

	while (readSection != NULL && arrayIndex < _size) {
		_arr[arrayIndex] = atoi(readSection); //atoi converts a stringfield to integer
		readSection = strtok(NULL, " "); //strok memorizes its last iteration and automatically jumps to next section
		arrayIndex++;
	}
}

void BubbleSort(int _arr[], int _size) {

	int swapped = 0;

	while (swapped == 0) {
		swapped = 1;
		for (int i = 0; i < _size - 1; i++)
		{
			if (_arr[i] > _arr[i + 1]) {
				int temp = _arr[i + 1];
				_arr[i + 1] = _arr[i];
				_arr[i] = temp;
				swapped = 0;
			}
		}
	}
}

