class Solution {
    public:
        bool isHappy(int n) {
            if (n == 1) {
                return true;
            }
            int a = n;
            int cvt = 0;
            unordered_set<int> s;
            s.insert(a);
            while (a != 1) {
                while (a) {
                    cvt += (a % 10) * (a % 10);
                    a /= 10;
                }
                a = cvt;
                cvt = 0;
                if (a == 1) {
                    return true;
                }
                if (s.find(a) != s.end()) {
                    return false;
                } else {
                    s.insert(a);
                }
            }
            return false;
        }
    };