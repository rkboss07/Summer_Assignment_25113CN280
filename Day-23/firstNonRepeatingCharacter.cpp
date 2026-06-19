#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    unordered_map<char,int> mp;

    for (char c: s) mp[tolower(c)]++;

    for (char c: s) {
        if (mp[tolower(c)]==1){
            cout << "First non-repeating Character is: "<<c<<endl;
            return 0;
        }
    }
    cout << "There are no non-repeating Characters"<<endl;
    return 1;

}