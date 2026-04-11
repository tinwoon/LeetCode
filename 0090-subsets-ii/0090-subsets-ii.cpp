class Solution {
public:
    std::set< std::vector<int> > ans;

    void calculate(vector<int> arrs, const std::vector<int>&nums, int lv){
        if(lv == -1){
            std::sort(arrs.begin(), arrs.end());
            ans.emplace(arrs);
            return;
        }

        calculate(arrs, nums, lv - 1);
        arrs.push_back(nums[lv]);
        calculate(arrs, nums, lv - 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector< std::vector<int> > v_ans;
        calculate(std::vector<int>(), nums, nums.size() -1);

        for(auto itr = ans.begin(); itr != ans.end(); itr++){
            v_ans.push_back(*itr);
        }

        return v_ans;
    }
};