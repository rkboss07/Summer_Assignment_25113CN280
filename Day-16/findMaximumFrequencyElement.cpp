#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> frequencyMap;
    for (int i = 0; i < n; i++) {
        frequencyMap[arr[i]]++;
    }
    int maxFrequency = 0;
    int mostFrequentElement = arr[0];
    for (const auto& pair : frequencyMap) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostFrequentElement = pair.first;
        }
    }
    cout << "The most frequent element is " << mostFrequentElement << " with a frequency of " << maxFrequency << "." << endl;
}