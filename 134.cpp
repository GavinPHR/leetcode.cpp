class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cumsum = 0;
        int lowest_idx = -1;
        int lowest_cumsum = INT_MAX;
        for (int i = 0; i < gas.size(); ++i) {
            cumsum += gas[i] - cost[i];
            if (cumsum < lowest_cumsum) {
                lowest_cumsum = cumsum;
                lowest_idx = i;
            }
        }
        return cumsum >= 0 ? (lowest_idx + 1) % gas.size() : -1;
    }
};