class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int myGas = 0;
            int index = 0;
            int i = 0;
            int circuit = 0;
    
            int isValid = 0;
            for (int i = 0; i < gas.size(); i++) {
                isValid = isValid + gas[i] - cost[i];
            }
            if (isValid < 0) {
                return -1;
            }
    
            while (circuit != cost.size()) {
                myGas = myGas + gas[i] - cost[i];
                i++;
                circuit++;
                if (i >= cost.size()) {
                    i = 0;
                }
                if (myGas < 0) {
                    myGas = 0;
                    index = i;
                    circuit = 0;
                }
            }
            return index;
        }
    };