#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            sum += v[i][j];
        }
    }

    vector<int> v1(n, 0); // Rows
    for (int i = 0; i < n; i++) {
        for (int j  = 0; j < m; j++) {
            v1[i] += v[i][j];
        }
    }

    vector<int> v2(m, 0); // Columns
    for (int j = 0; j < m; j++) {
        for (int i  = 0; i < n; i++) {
            v2[j] += v[i][j];
        }
    }

    int minNum = INT_MAX;
    int rowSum = 0;
    for (int i = 0; i < n; i++) {
        rowSum += v1[i];
        minNum = min(minNum, abs(sum - rowSum - rowSum));
    }

    int columnSum = 0;
    for(int j = 0; j < m; j++) {
        columnSum += v2[j];
        minNum = min(minNum, abs(sum - columnSum * 2));
    }
    
    cout << minNum << endl;
} 