/*
* 13. Movie Statistics
* Write a program that can be used to gather statistical data about the number of movies
  college students see in a month. The program should perform the following steps:
  A) Ask the user how many students were surveyed. An array of integers with this
  many elements should then be dynamically allocated.
  B) Allow the user to enter the number of movies each student saw into the array.
  C) Calculate and display the average, median, and mode of the values entered. (Use
  the functions you wrote in Problems 8 and 9 to calculate the median and mode.)
  Input Validation: Do not accept negative numbers for input.
*/

#include <iostream>
#include <iomanip>
#include <cassert>
#include<stdio.h>
#include <cmath>
double getAverage(int*, int);
double getMedian(int*, int);
void bubbleSort(int*, int);
void swap(int*, int, int);
void mode(int*, int);

using namespace std;


int main() {
	int survey_total = 0;

	do {
		cout << "How many students were surveyed? Must be a positive integer ";
		cin >> survey_total;
	} while (survey_total < 0);

	int* ptr = new int[survey_total];

	for (int i = 0; i < survey_total; i++) {
		cout << "\nEnter the amount of movies student " << i + 1 << " saw: ";
		cin >> *(ptr + i);
	}

	for (int i = 0; i < survey_total; i++) {
		cout << "\n\tStudent " << i + 1 << " saw " << *(ptr + i) << " movies";
	}

	cout << "\n\tThe students watched an average of " << fixed << setprecision(2) << getAverage(ptr, survey_total);

	bubbleSort(ptr, survey_total);

	 cout << "\n\tThe median values is " << fixed << setprecision(2) << getMedian(ptr, survey_total);

	 mode(ptr, survey_total);
}

double getAverage(int* arr, int size) {
	double total = 0;

	for (int i = 0; i < size; i++) {
		total += *arr++;
	}	
	return (total / size);
}


double getMedian(int* arr, int size) {
	int midvalue, midvalue2;
	bubbleSort(arr, size);
	if (size % 2 == 0) {
		midvalue = (size / 2) - 1;
		 cout << "\n\nthe mid value is " << arr[midvalue];
		midvalue2 = midvalue + 1;
		cout << "\n\nthe mid value 222 is " << arr[midvalue2];
		return (arr[midvalue] + arr[midvalue2]) / 2.0;
		}
	else {
		midvalue = size / 2;
		return arr[midvalue];
	}
}

void bubbleSort(int* arr, int size) {
	for (int x = size; x > 0; x--) {
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr, i, i + 1);
			}
		}
	}
}

void swap(int* arr, int firstVal, int secondVal) {
	int temp = arr[firstVal];
	arr[firstVal] = arr[secondVal];
	arr[secondVal] = temp;
}

void mode(int* arr, int size) {
	bubbleSort(arr, size);

	for (int i = 0; i < size; i++) {
		cout << "---" << arr[i];
	}

	int* counter = new int[size];

	int count = 1;
	int countIndex = 0;
	for (int i = 0; i < size - 1; i++) {
		cout << "\nComparing " << arr[i] << " with " << arr[i + 1];
		if (arr[i] == arr[i + 1]) {
			count++;
			if (i == size - 2) {
				cout << "it got called at index " << countIndex;
				counter[countIndex] = count;
				countIndex++;
			}
		}
		else {
			counter[countIndex] = count;
			countIndex++;
			count = 1;
		}
	}
	
	if (countIndex == 0) {
		counter[countIndex] = 1;
		countIndex++;
	}
	// Need to add code find way to make mode function work if the
	// greatest value occurs once. Ex. this data set wont work 2--5-3-8-1

	for (int i = 0; i < (countIndex); i++) {
		cout << "\n\n\tOccurences" << counter[i];
	}
}

// sort array
// first value equals num. check the subsequent values. add one to count until the next value does not equal num. 
// add count to counter array.
// set num equal to the next number repeat process.
// then check the next value. 


// compare 1 and 2 elements next to each other 
// if they are equal increase count
// compare 2 and 3 elements are they equal 
// if yes increase count
// compare the 3 and fourth elements
// are they equal? 
// no. add count to new array. set count to 0.
//  compare 4th and 5th elements 