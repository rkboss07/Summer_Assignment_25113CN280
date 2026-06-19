#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    unordered_map<char,int> mp;

    for (char c: s) mp[tolower(c)]++;
    int maxOccurence=0;
    char maxOccuringCharacter; 
    vector<char> characters;

    for (auto p: mp) {
        if (p.second>maxOccurence){
            maxOccurence=p.second;
            maxOccuringCharacter=p.first;
        }
    }
    for (auto p: mp) {
        if (p.second==maxOccurence){
            characters.push_back(p.first);
        }
    }
    
    cout << "The characters that occur the most are: ";
    for (char c: characters) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}