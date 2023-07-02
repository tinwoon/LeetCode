class Solution {
public:
    std::vector< std::vector<int> > ans;
    
    //몇번째까지 체크했는지 안했는지 여부, 비트마스크 기준으로 idx 넣었을 시의 값
    void calculate(int level, int idx, std::vector<int>& nums){
        if(level == 0){
            std::vector<int> ret;
            for(int k = 0; k < nums.size(); k++){
                if(idx & (1 << k)) ret.emplace_back(nums[k]);
            }
            ans.emplace_back(ret);
            return;
        }
        
        //미추가
        calculate(level - 1, idx, nums);
        //추가
        calculate(level - 1, idx | (1<<(nums.size() - level)), nums);


    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        calculate(nums.size(), 0, nums);
        return ans;
    }
};