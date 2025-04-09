class Solution {
public:
    vector<int> p;
    vector<vector<int>> v;
    int sum = 0;
    void backtracking(int n, int k, int index) {
        if (p.size() == k) {
            if (sum == n) {
                v.push_back(p);
            }
            return;
        }

        for (int i = index; i <= n && i <= 9; i++) {
            sum += i;
            p.push_back(i);
            backtracking(n, k, i + 1);
            p.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 1);
        return v;
    }
};