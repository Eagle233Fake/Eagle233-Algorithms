class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> a;
            unordered_set<int> b(nums1.begin(), nums1.end());
            for (int i : nums2) {
                if (b.find(i) != b.end()) {
                    a.insert(i);
                }
            }
            
            return vector<int>(a.begin(), a.end());
        }
    };