#include <iostream> 

using namespace std;

int main(){
    int num1, num2;
    
    cout << "Enter a number: ";
    cin >> num1;

    cout << "\nEnter another number: ";
    cin >> num2;

    if(num1 > num2)
    {
        cout << num1;
    }
    else{
        cout << num2;
    }

}