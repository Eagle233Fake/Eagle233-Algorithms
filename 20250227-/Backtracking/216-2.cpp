class Solution {
public:
    vector<int> p;
    vector<vector<int>> v;
    int sum = 0;
    void backtracking(int k, int n, int index) {
        if (k == p.size()) {
            if (sum == n) {
                v.push_back(p);
            }
            return;
        }

        for (int i = index; i <= 10 - k + p.size(); i++) { // 9 - x + 1 == k - p.size()
            sum += i;
            if (sum > n) {
                sum -= i;
                return;
            }
            p.push_back(i);
            backtracking(k, n, i + 1);
            p.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return v;
    }
};