class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            vector<int> minLeftIndex(heights.size());
            vector<int> minRightIndex(heights.size());
    
            minLeftIndex[0] = -1;
            for (int i = 1; i < heights.size(); i++) {
                int t = i - 1;
                while (t >= 0 && heights[t] >= heights[i]) {
                    t = minLeftIndex[t];
                }
                minLeftIndex[i] = t;
            }
    
            minRightIndex[heights.size() - 1] = heights.size();
            for (int i = heights.size() - 2; i >= 0; i--) {
                int t = i + 1;
                while (t < heights.size() && heights[t] >= heights[i]) {
                    t = minRightIndex[t];
                }
                minRightIndex[i] = t;
            }
    
            int result = 0;
            for (int i = 0; i < heights.size(); i++) {
                result = max(result, (minRightIndex[i] - minLeftIndex[i] - 1) * heights[i]);
            }
    
            return result;
        }
    };