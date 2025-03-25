class Solution {
public:
    vector<int> path;
    vector<vector<int>> v;

    void backtracking(int n, int k, int index) {
        if (path.size() == k) {
            v.push_back(path);
            return;
        }

        if (n - index + 1 < k - path.size()) {
            return;
        }

        for (int i = index; i <= n; i++) {
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