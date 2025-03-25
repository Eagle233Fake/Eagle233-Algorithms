class Solution {
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
            unordered_map<int, int> m;
            for (int i : nums1) {
                for (int j : nums2) {
                    m[i + j]++;
                }
            }
    
            int count = 0;
            for (int i : nums3) {
                for (int j : nums4) {
                    if (m[-i - j]) {
                        count += m[-i - j];
                    }
                }
            }
    
            return count;
        }
    };