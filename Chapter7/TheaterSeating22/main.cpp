// Chapter 7 Arrrays and Vectors Programming Challenge #22 Page 461


#include <iostream>
#include <iomanip>
#include <string>
#include "input.h"
using namespace std;

const int COLS = 20;
const int seat_cost = 20;
void display_seats(string arr[][COLS], int);
void show_total(int*, int*, int, int );

int main() {
	const int ROWS = 10;
	const int TOTAL_SEATS = ROWS * COLS;
	string arr[ROWS][COLS];
	
	int tickets_needed = 0;
	int count = 0;
	int tickets_available = TOTAL_SEATS;

	int* rowPtr = new int[TOTAL_SEATS];
	int* seatPtr = new int[TOTAL_SEATS];

	// Initialize array of seats with "**" which represents that a seat is empty
	for (int i = 0; i < ROWS; i++) {
		for (int x = 0; x < COLS; x++) {
			arr[i][x] = "**";
		}
	}

				display_seats(arr, ROWS);
		
				tickets_needed = inputInteger("\n\t\How many tickets would you like to purchase? ", 1, tickets_available);

				// get row and seat number from user
				for (int i = 0; i < tickets_needed; i++) {
					int rowNum = inputInteger(("\n\n\t\tWhich row would you like for ticket " + to_string(i + 1) + ": "), 1, ROWS);
					int seatNum = inputInteger(("\n\t\tEnter the column: "), 1, COLS);

					// if that seat is taken ask the user to enter another seat until they choose an open seat
					if (arr[rowNum - 1][seatNum - 1] == "##") {
						do {
							display_seats(arr, ROWS);
							cout << "\n\n\t\tThat seat is no longer available. Please choose a different seat.";
							rowNum = inputInteger(("\n\t\tWhich row would you like for ticket " + to_string(i + 1) + ": "), 1, ROWS);
							seatNum = inputInteger(("\n\t\tEnter the column: "), 1, COLS);

						} while (arr[rowNum - 1][seatNum - 1] == "##");
					}

					// change the users chosen seat number in "arr" to "##" which represents that it is taken
					cout << "\n\t\tAdding ticket at row " << rowNum << " column " << seatNum << " to cart.";
					arr[rowNum - 1][seatNum - 1] = "##";
					// keep track of the row and seat numbers that are taken
					rowPtr[i] = rowNum;
					seatPtr[i] = seatNum;
					count++;
				}
				cout << "\n\n";

				show_total(rowPtr, seatPtr, count, seat_cost);
			}
		
			// Precondition: arr must be a 2D array of strings of either "**" or "##" values
			//               which represent the seats that are available or taken.
			// Postcondition: print out the seating chart
			void display_seats(string arr[][COLS], int size) {
				system("cls");
				cout << "\n\t\tTicket price: $" << seat_cost;
				cout << "\n\n\t\tAvailable seats = **\t\tUnavailable seats == ##";
				cout << "\n\t\t\t\t\tSeats";
				cout << "\n\t\t01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20";
				for (int i = 0; i < size; i++) {
					cout << "\n\n";
					cout << "\tRow " << i + 1 << "\t";
					for (int x = 0; x < COLS; x++) {
						cout << arr[i][x] << " ";
					}
					}
				}

			// Precondition: rows and seat must be pointers. tickets and cost must be positive integers
			// Poscondition: print out the tickets purchased and the total cost
				void show_total(int* rows, int* seat, int tickets, int cost) {
					cout << "\n\t\tPurchase Total\n\t\t";
					cout << string(29, char(205));
					
					for (int i = 0; i < tickets; i++) {
						cout << "\n\t\tTicket " << setw(2) << i + 1 << ": row - " << setw(2) << rows[i] << " seat - " << setw(2) << seat[i];
					}
					cout << "\n\t\tTotal cost: $" << setprecision(2) << showpoint << cost * tickets;
				}
