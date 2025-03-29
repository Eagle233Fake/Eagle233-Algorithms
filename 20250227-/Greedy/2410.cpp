class Solution {
    public:
        int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
            sort(players.begin(), players.end());
            sort(trainers.begin(), trainers.end());
    
            int count = 0;
            for (int i = players.size() - 1, j = trainers.size() - 1; i >= 0 && j >= 0; ) {
                if (players[i] <= trainers[j]) {
                    count++;
                    i--;
                    j--;
                } else {
                    i--;
                }
            }
            return count;
        }
    };