class Solution {
    public:
        int jump(vector<int>& nums) {
            int step = 0;
            int cur = 0;
            int next = 0;
            for (int i = 0; i < nums.size(); i++) {
                next = max(i + nums[i], next);
                if (cur == i) {
                    if (cur != nums.size() - 1) {
                        cur = next;
                        next = 0;
                        step++;
                        if (cur >= nums.size() - 1) {
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
            return step;
        }
    };