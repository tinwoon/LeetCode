class Solution {
public:
    std::vector< std::vector<int> > ans;
    std::vector<int> NUMS;
    
    //몇번째까지 체크했는지 안했는지 여부, 비트마스크 기준으로 idx 넣었을 시의 값
    void calculate(int level, int idx){
        if(level == 0){
            std::vector<int> ret;
            for(int k = 0; k < NUMS.size(); k++){
                if(idx & (1 << k)) ret.emplace_back(NUMS[k]);
            }
            ans.emplace_back(ret);
            return;
        }
        
        //미추가
        calculate(level - 1, idx);
        //추가
        calculate(level - 1, idx | (1<<(NUMS.size() - level)));


    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        NUMS = nums;
        calculate(nums.size(), 0);
        return ans;
    }
};