/*
* 12. Element Shifter
  Write a function that accepts an int array and the array s size as arguments. The
  function should create a new array that is one element larger than the argument array.
  The rst element of the new array should be set to 0. Element 0 of the argument array
  should be copied to element 1 of the new array, element 1 of the argument array
  should be copied to element 2 of the new array, and so forth. The function should
  return a pointer to the new array
*/

#include <iostream>
int* shiftArr(int arr[], int size);
using namespace std;

int main() {
	const int SIZE = 15;
	int arr[SIZE] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	cout << "Array of numbers:\n";
	for (int val : arr) {
		cout << val << "  ";
	}
	cout << "\nCopy of array of numbers shifted 1 subscript forward:\n";

	int* arrPtr = shiftArr(arr, SIZE);

	for (int i = 0; i < SIZE +1; i++) {
		cout << arrPtr[i] << "  ";
	}
}

int* shiftArr(int arr[], int size) {

	int* ptr = nullptr;

	if (size < 0) {
		return ptr;
	}

	int newSize = size + 1;
	ptr = new int[newSize];
	ptr[0] = 0;
	int i = 0;
	for (int y = 1; y < newSize; y++, i++) {
		ptr[y] = arr[i];
	}

	return ptr;
}