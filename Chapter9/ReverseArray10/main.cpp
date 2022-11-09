/* Write a function that accepts an int array and the array size as arguments. The
  function should create a copy of the array, except that the element values should be
  reversed in the copy. The function should return a pointer to the new array.
  Demonstrate the function in a complete program.
*/
#include <iostream>

int* reverseArray(int[], int);
using namespace std;

int main() {
	const int SIZE = 5;
	int arrayNums[SIZE] = { 1,2,3,4,5 };
	cout << "Array in regular order:\n";
	for (int val : arrayNums) {
		cout << val << "  ";
	}
	int* ptr = reverseArray(arrayNums, SIZE);
	cout << "\nCopy of array in reverse order:\n";
	for (int i = 0; i < SIZE; i++) {
		cout << ptr[i] << "  ";
	}	
}

// Precondition: "arr" has to be a valid integer array. "size" has to be equal to the size of the "arr" array
// Postondition: a new array is made as a copy of the "arr" array elements in reverse order. A pointer to 
//				 the new array is returned.
int* reverseArray(int arr[], int size) {
	int* arrPtr = new int[size];
	int y = 0;
	for (int i = size - 1; i >= 0; i--, y++) {
		arrPtr[y] = arr[i];
	}
	return arrPtr;
}


