class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int slow = 1;
            int fast = nums.size() - 1;
            vector<vector<int>> v;
            for (int i = 0; i < nums.size(); i++) {
                slow = i + 1;
                fast = nums.size() - 1;
                if (nums[i] > 0) {
                    break;
                }
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                while (slow < fast) {
                    if (nums[i] + nums[slow] + nums[fast] > 0) {
                        fast--;
                    } else if (nums[i] + nums[slow] + nums[fast] < 0) {
                        slow++;
                    } else {
                        v.push_back({nums[i], nums[slow], nums[fast]});
                        while (slow < fast && nums[slow] == nums[slow + 1]) {
                            slow++;
                        }
                        while (slow < fast && nums[fast] == nums[fast - 1]) {
                            fast--;
                        }
                        slow++;
                        fast--;
                    }
                }
            }
            return v;
        }
    };