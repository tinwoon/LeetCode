class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        std::vector<int> ans;
        
        std::sort(nums.begin(), nums.end());
        
        for(int idx = 0; (idx < nums.size() - 1) && (ans.size() < 2);){
            if(nums[idx] != nums[idx + 1]){
                ans.emplace_back(nums[idx++]);
            } else idx+=2;
        }
        if(ans.size() < 2) ans.emplace_back(nums[nums.size() - 1]);
        
        return ans;
    }
};