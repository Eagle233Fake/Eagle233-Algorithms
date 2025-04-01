class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            map<int, int> m;
            for (int i = 0; i < bills.size(); i++) {
                if (bills[i] == 5) {
                    m[5]++;
                } else if (bills[i] == 10) {
                    if (m[5] > 0) {
                        m[5]--;
                        m[10]++;
                    } else {
                        return false;
                    }
                } else {
                    if (m[10] > 0) {
                        if (m[5] > 0) {
                            m[10]--;
                            m[5]--;
                        } else {
                            return false;
                        }
                    } else {
                        if (m[5] > 2) {
                            m[5] -= 3;
                        } else {
                            return false;
                        }
                    }
                }
            }
    
            return true;
        }
    };