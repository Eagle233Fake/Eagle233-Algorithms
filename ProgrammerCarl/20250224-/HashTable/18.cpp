class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> v;
            for (int i = 0; i < nums.size(); i++) { // nums.size() 返回的是无符号整型，越界
                if (nums[i] > target && nums[i] > 0) {
                    break;
                }
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[i] + nums[j] > target && nums[j] > 0) {
                        break;
                    }
                    if (j > i + 1 && nums[j] == nums[j - 1]) {
                        continue;
                    }
                    int left = j + 1;
                    int right = nums.size() - 1;
                    while (left < right) {
                        if ((long long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
                            left++;
                        } else if ((long long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
                            right--;
                        } else {
                            v.push_back({nums[i], nums[j], nums[left], nums[right]});
                            while (left < right && nums[left] == nums[left + 1]) {
                                left++;
                            }
                            while (left < right && nums[right] == nums[right - 1]) {
                                right--;
                            }
                            left++;
                            right--;
                        }
                    }
                }
            }
            return v;
        }
    };