class Solution {
    public:
        int trap(vector<int>& height) {
            vector<int> maxLeft(height.size(), height[0]);
            vector<int> maxRight(height.size(), height[height.size() - 1]);
    
            for (int i = 1; i < height.size(); i++) {
                maxLeft[i] = max(maxLeft[i - 1], height[i]);
            }
            for (int i = height.size() - 2; i >= 0; i--) {
                maxRight[i] = max(maxRight[i + 1], height[i]);
            }
    
            int result = 0;
            for (int i = 0; i < height.size(); i++) {
                result += min(maxLeft[i], maxRight[i]) - height[i];
            }
    
            return result;
        }
    };