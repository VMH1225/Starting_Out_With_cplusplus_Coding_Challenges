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

using namespace std;

int main() {
	int survey_total = 0;
	cout << "How many students were surveyed? ";
	cin >> survey_total;

	int* ptr = new int[survey_total];

	for (int i = 0; i < survey_total; i++) {
		cout << "\nEnter the amount of movies student " << i + 1 << " saw: ";
		cin >> *ptr;
		ptr++;
	}

	for (int i = 0; i < survey_total; i++) {
		cout << "\n\tStudent " << i + 1 << " saw " << *(ptr + i) << " movies";
	}
}