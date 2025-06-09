#include <bits/stdc++.h>

using namespace std;

unordered_set<string> uset = {
    "the",
    "an",
    "a",
    "of",
    "for",
    "and"
};

void solve(void) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string word;
    int count = 0;
    while (ss >> word) {
        for (char &c : word) {
            c = tolower(c);
        }

        if (uset.find(word) == uset.end()) {
            count++;
        }
    }

    cout << count << endl;
}

int main(void) {
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
    }
}