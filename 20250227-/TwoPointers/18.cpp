class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> v;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > target && nums[i] >= 0) {
                    break;
                }
                if (i > 0 && nums[i - 1] == nums[i]) {
                    continue;
                }
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                        break;
                    }
                    if (j > i + 1 && nums[j - 1] == nums[j]) {
                        continue;
                    }
                    int slow = j + 1;
                    int fast = nums.size() - 1;
                    while (slow < fast) {
                        long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[slow] + nums[fast];
                        if (sum < target) {
                            slow++;
                        } else if (sum > target) {
                            fast--;
                        } else {
                            v.push_back({nums[i], nums[j], nums[slow], nums[fast]});
                            slow++;
                            fast--;
                            while (slow < fast && nums[slow] == nums[slow - 1]) {
                                slow++;
                            }
                            while (slow < fast && nums[fast] == nums[fast + 1]) {
                                fast--;
                            }
                        }
                    }
                }
            }
            return v;
        }
    };