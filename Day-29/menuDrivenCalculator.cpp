#include <iostream>
#include <cmath>

using namespace std;

void inputTwoNumbers(float &num1, float &num2) {
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
}
int main() {
    int choice;   
    do {
        cout << "Menu Driven Calculator" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        float num1, num2, result;

        switch (choice) {
            case 1:
                inputTwoNumbers(num1, num2);
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;
            case 2:
                inputTwoNumbers(num1, num2);
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;
            case 3:
                inputTwoNumbers(num1, num2);
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;
            case 4:
                inputTwoNumbers(num1, num2);
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            case 5:
                inputTwoNumbers(num1, num2);
                if (num2 != 0) {
                    result = fmod(num1, num2);
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Modulus by zero!" << endl;
                }
                break;
            case 6:
                cout << "Exiting the calculator." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);
}