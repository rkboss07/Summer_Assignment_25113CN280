#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;



    vector<pair<int, int>> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int to_search;
    cout << "Enter the element to search: ";
    cin >> to_search;

    int low=0, high = n-1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].first == to_search) {
            res = arr[mid].second;
            break;
        }
        else if (arr[mid].first > to_search) high = mid -1;
        else low = mid+1;
    }

    if (res!=-1) cout << to_search << " Found at Index: "<< res<<endl;
    else cout<<to_search << " Not found in array."<<endl;
}