#include <bits/stdc++.h>

using namespace std;

bool isAo(int a) {
    string A = to_string(a);
    int cvt = 0;
    int i = 0;

    bool one = false;
    bool two = false;

    for (; i < A.size() - 1; i++) {
        if (A[i] > A[i + 1]) {
            one = true;
            cvt++;
        } else {
            break;
        }
    }

    for (; i < A.size() - 1; i++) {
        if (A[i] < A[i + 1]) {
            cvt++;
            two = true;
        }
    }

    if (cvt == A.size() - 1 && one && two) {
        return true;
    }
    return false;
}

int main(void) {
    vector<bool> ao(1000001, false);

    for (int i = 100; i <= 1000000; i++) {
        ao[i] = isAo(i);
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "case #" << i << ':' << endl;
        int a, b;
        cin >> a >> b;
        int count = 0;
        for (int i = a; i <= b; i++) {
            if (ao[i]) {
                count++;
            }
        }

        cout << count << endl;
    }
}