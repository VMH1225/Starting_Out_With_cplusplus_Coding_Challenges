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
		cout << "How many students were surveyed? (Must be a positive integer): ";
		cin >> survey_total;
	} while (survey_total < 0);

	int* ptr = new int[survey_total];

	for (int i = 0; i < survey_total; i++) {
		cout << "\nEnter the amount of movies student " << i + 1 << " saw: ";
		cin >> *(ptr + i);
	}

	for (int i = 0; i < survey_total; i++) {
		if (*(ptr + i) == 1) {
			cout << "\n\tStudent " << i + 1 << " saw " << *(ptr + i) << " movie";
		}
		else {
			cout << "\n\tStudent " << i + 1 << " saw " << *(ptr + i) << " movies";
		}
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
		midvalue2 = midvalue + 1;
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
	int* counter = new int[size];
	int greatest = 0;
	int count = 1;
	int countIndex = 0;
	int total = 0;
	//added if statement to see if the values being added to count array is equal to the greatest occurences.
	//For example,if 2 appears twice then the if statement sets it as the greatest value. Maybe need to make a separate for loop
	// for this operation. No you do have to make a separate for loop to implement this.
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			count++;
			if (i == size - 2) {
				counter[countIndex] = count;
				countIndex++;
				total += count;
			}
		}
		else {
			counter[countIndex] = count;
			countIndex++;
			total += count;
			count = 1;
		}
		cout << "\nvalues counted " << total;
	}
	
	// causes function to work correctly if there is only one number in list 
	if (countIndex == 0) {
		cout << "\n\t" << arr[0] << " is one of the modes";
		greatest += 1;
		counter[countIndex] = 1;
		total += count;
		countIndex++;
		cout << "\nvalues counted only one value " << total;

	}


	if (total < size) {
		if (count < 2 && greatest == 1) {
			cout << "\n\t" << arr[size - 1] << " is one of the modes";
		}
		counter[countIndex] = 1;
		countIndex++;
	}

	int mostOccurences = counter[0];
	for (int i = 0; i < (countIndex); i++) {
		if (mostOccurences < counter[i]) {
			mostOccurences = counter[i];
		}
	}

	cout << "\n\n";
		for (int i = 0; i < size; i++) {
			cout << "---" << arr[i];
	}
	cout << "\n\nThe count equals before" << count;
	count = 1;
	cout << "\ntotal values counted " << total << "\ntotal values in array" << size << "\n most occurences " << mostOccurences;
	//final step have values displayed if their count is equal to most occurences
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			if ((count + 1) <= mostOccurences) {
				count++;
			}
			cout << "\n\nThe count equals during loop" << count;
			if (count == mostOccurences) {
				cout << "\n\nMode hi: " << arr[i];
				count = 1;
			}
		}
		else if(count == mostOccurences) {
				cout << "\n\nMode: " << arr[i];
				count = 1;
		}
		else {
				count = 1;
			}
		}
	

	
	if (total < size && mostOccurences == 1) {
			cout << "\n\t" << arr[size - 1] << " is one of the modes";
	}

}




	//cout << "\n\n";
	//for (int i = 0; i < size; i++) {
	//	cout << "--" << arr[i];
	//}

	//cout << "\n\nThe greatest value appears " << val << " times";
	// does not work for 1, 1, 3, 4, 5, 5, 8 data set. when their is a value in between 2 modes it does not get the 2nd correct mode
	  



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