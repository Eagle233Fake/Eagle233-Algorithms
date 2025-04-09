class Solution {
    public:
        unordered_map<string, map<string, int>> targets;
    
        bool backtracking(int ticketsNum, vector<string> &result) {
            if (result.size() == ticketsNum + 1) {
                return true;
            }
    
            for (pair<const string, int> &target : targets[result[result.size() - 1]]) {
                if (target.second != 0) {
                    target.second--;
                    result.push_back(target.first);
                    if (backtracking(ticketsNum, result)) {
                        return true;
                    }
                    target.second++;
                    result.pop_back();
                }
            }
    
            return false;
        }
    
        vector<string> findItinerary(vector<vector<string>>& tickets) {
            vector<string> result;
            for (vector<string> v : tickets) {
                targets[v[0]][v[1]]++;
            }
            result.push_back("JFK");
            backtracking(tickets.size(), result);
            return result;
        }
    };