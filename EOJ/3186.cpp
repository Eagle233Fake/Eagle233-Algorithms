#include <bits/stdc++.h>

using namespace std;

unordered_map<string, char> umap = {
    {"zero", '0'},
    {"one", '1'},
    {"two", '2'},
    {"three", '3'},
    {"four", '4'}, 
    {"five", '5'},
    {"six", '6'},
    {"seven", '7'},
    {"eight", '8'},
    {"nine", '9'},
};

void solve(void) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string s;
    string A, B;
    bool isA = true;
    while (ss >> s) {
        if (umap[s]) {
            if (isA) {
                A += umap[s];
            } else {
                B += umap[s];
            }
        } else {
            isA = false;
        }
    }

    int a = stoi(A);
    int b = stoi(B);

    cout << a + b << endl;

}

int main(void) {
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
    }

    return 0;
}