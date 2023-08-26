class Solution {
public:
    
    int TG;
    std::vector<int> CD;
    std::vector< std::vector<int> > ans;
    
    void calculate(int val, int idx, std::vector<int> input){
        
        if(val == TG){
            ans.emplace_back(input);
            return;
        }
        
        for(int k=idx; k < CD.size(); k++){
            if(val + CD[k] <= TG){
                input.emplace_back(CD[k]);
                calculate(val+CD[k], k, input);
                input.pop_back();
            } 
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        CD = candidates;
        TG = target;
        calculate(0, 0, std::vector<int>());
        return ans;
    }
};