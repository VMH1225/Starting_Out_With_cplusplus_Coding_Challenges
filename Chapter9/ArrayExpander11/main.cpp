/* Chapter 9 Pointers  page 555
* 11) Array Expander
* Write a function that acccepts an int array and the array's size as arguments. The function should create a new array that is
* twice the size of the argument array. The function should copy the contents of the argument array to the new array and initialize
* the unused elements of the second array with 0. The function should return a pointer to the new array.
*/

#include <iostream>

int* copyValuesDoubleSizeOfArray(int arr[], int size);
using namespace std;

int main() {	
	const int SIZE = 10;
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++) {
		arr[i] = i;
	}
	
	for (int val : arr) {
		cout << val << endl;
	}
	int* ptr1 = nullptr;

	ptr1 = copyValuesDoubleSizeOfArray(arr, SIZE);

	for (int i = 0; i < SIZE * 2; i++) {
		cout << ptr1[i] << endl;
	}
}


int* copyValuesDoubleSizeOfArray(int arr[], int size) {
	int* ptr = nullptr;
	const int DOUBLE_SIZE = size * 2;
	ptr = new int[DOUBLE_SIZE];

	for (int i = 0; i < DOUBLE_SIZE; i++) {
		if (i < size) {
			ptr[i] = arr[i];
		}
		else {
			ptr[i] = 0;
		}
	}
	return ptr;
}
