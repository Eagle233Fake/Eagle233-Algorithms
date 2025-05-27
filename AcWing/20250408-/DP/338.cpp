#include <bits/stdc++.h>

using namespace std;

int getNum(vector<int> &nums, int r, int l) {
    int i = r;
    int res = 0;
    while (i >= l) {
        res *= 10;
        res += nums[i];
        i--;
    }
    return res;
}

int count(int a, int x) {
    vector<int> nums;
    while (a) {
        nums.push_back(a % 10);
        a /= 10;
    }

    a = nums.size();

    int res = 0;
    for (int i = a - 1 - (!x); i >= 0; i--) {
        if (i < a - 1) {
            res += getNum(nums, a - 1, i + 1) * pow(10, i);
            if (x == 0) {
                res -= pow(10, i);
            }
        }
        if (nums[i] == x) {
            res += getNum(nums, i - 1, 0) + 1;
        }
        if (nums[i] > x) {
            res += pow(10, i);
        }
    }

    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            break;
        }

        if (a > b) {
            swap(a, b);
        }

        for (int i = 0; i < 10; i++) {
            cout << count(b, i) - count(a - 1, i) << ' ';
        }

        cout << endl;
    }
    return 0;
}
