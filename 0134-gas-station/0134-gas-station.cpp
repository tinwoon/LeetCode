class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_tank = 0, k_to_tank = 0, ret = 0;
        
        for(int k = 0; k < n; k++){
            total_tank += (gas[k] - cost[k]);
            k_to_tank += (gas[k] - cost[k]);
            
            if(k_to_tank < 0){
                ret = k + 1;
                k_to_tank = 0;
            }
        }
        return (total_tank < 0) ? -1 : ret;
    }
};