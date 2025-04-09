class Solution {
public:
    vector<int> path;
    vector<vector<int>> v;

    void backtracking(int n, int k, int index) {
        if (path.size() == k) {
            v.push_back(path);
            return;
        }

        for (int i = index; i <= n - k + path.size() + 1; i++) {  // n - x + 1 == k - path.size()
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return v;
    }
};