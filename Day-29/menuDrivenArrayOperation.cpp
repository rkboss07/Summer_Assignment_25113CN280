#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//function prototypes
void sortNumbers(vector<int>& numbers, int choice);
void searchNumber(const vector<int>& numbers, int target);
void deleteNumber(vector<int>& numbers, int target);
void sumNumbers(const vector<int>& numbers);

int main() {
    vector<int> numbers;
    int size, choice;
    cout << "Enter the number of elements: ";
    cin >> size;
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Sort Numbers\n";
        cout << "2. Search Number\n";
        cout << "3. Delete Number\n";
        cout << "4. Sum of Numbers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter 1 for ascending, 2 for descending: ";
                cin >> choice;
                sortNumbers(numbers, choice);
                break;
            case 2:
                int target;
                cout << "Enter the number to search: ";
                cin >> target;
                searchNumber(numbers, target);
                break;
            case 3:
                cout << "Enter the number to delete: ";
                cin >> target;
                deleteNumber(numbers, target);
                break;
            case 4:
                sumNumbers(numbers);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

void sortNumbers(vector<int>& numbers, int choice) {
    if (choice == 1) {
        sort(numbers.begin(), numbers.end());
        cout << "Numbers sorted in ascending order: ";
    } else if (choice == 2) {
        sort(numbers.rbegin(), numbers.rend());
        cout << "Numbers sorted in descending order: ";
    } else {
        cout << "Invalid choice!" << endl;
        return;
    }
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

void searchNumber(const vector<int>& numbers, int target) {
    auto it = find(numbers.begin(), numbers.end(), target);
    if (it != numbers.end()) {
        cout << "Number " << target << " found at position: " << distance(numbers.begin(), it) + 1 << endl;
    } else {
        cout << "Number " << target << " not found in the list." << endl;
    }
}

void deleteNumber(vector<int>& numbers, int target) {
    auto it = remove(numbers.begin(), numbers.end(), target);
    if (it != numbers.end()) {
        numbers.erase(it, numbers.end());
        cout << "Number " << target << " deleted from the list." << endl;
    } else {
        cout << "Number " << target << " not found in the list." << endl;
    }
}

void sumNumbers(const vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    cout << "Sum of the numbers: " << sum << endl;
}