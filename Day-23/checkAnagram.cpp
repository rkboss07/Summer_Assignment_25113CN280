#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string s1;
    cout << "Enter a string: ";
    cin >> s1;

    unordered_map<char,int> mp;

    for (char c: s1) mp[tolower(c)]++;

    string s2;
    cout << "Enter the string to check anagram: ";
    cin >> s2;

    for (char c: s2) mp[tolower(c)]--;

    for (auto p: mp) {
        if (p.second!=0){
            cout << "The strings are not anagrams"<<endl;
            return 1;
        }
    }
    cout << "The strings are anagrams." << endl;
    return 0;
}