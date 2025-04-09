class Solution {
    public:
        class myQueue {
        public:
            deque<int> d;
    
            void pop(int val) {
                if (!d.empty() && d.back() == val) {
                    d.pop_back();
                }
            }
    
            void push(int val) {
                while (!d.empty() && d.front() < val) {
                    d.pop_front();
                }
                d.push_front(val);
            }
    
            int getMaxValue() {
                return d.back();
            }
        };
    
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            myQueue q;
            vector<int> v;
            for (int i = 0; i < k; i++) {
                q.push(nums[i]);
            }
            v.push_back(q.getMaxValue());
            for (int i = 0; i < nums.size() - k; i++) {
                q.push(nums[i + k]);
                q.pop(nums[i]);
                v.push_back(q.getMaxValue());
            }
            return v;
        }
    };