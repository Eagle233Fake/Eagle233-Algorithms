class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int curGas = 0;
            int totalGas = 0;
            int index = 0;
            for (int i = 0; i < gas.size(); i++) {
                totalGas = totalGas + gas[i] - cost[i];
                curGas = curGas + gas[i] - cost[i];
                if (curGas < 0) {
                    index = i + 1;
                    curGas = 0;
                }
    
                if (i == gas.size() - 1 && totalGas < 0) {
                    return -1;
                }
            }
            return index;
        }
    };