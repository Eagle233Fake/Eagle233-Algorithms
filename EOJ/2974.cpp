#include <bits/stdc++.h>

using namespace std;

void solve(void) {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    int cvt = 0;
    while (ss >> word) {
        for (char &c : word) {
            c = tolower(c);
        }
        if (word == "the" || word == "a" || word == "an" || word == "of" || word == "for" || word == "and") {
            continue;
        }
        cvt++;
    }

    cout << cvt << endl;
}

int main(void) {
    int T;
    cin >> T;
    getchar();
    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
    }
}