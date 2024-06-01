class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        if((nums.size() <= 1) || nums[0] != nums[1]) return nums[0];
        
        for(int k = 1; k < nums.size() - 1; k++){
            if(nums[k-1] != nums[k] && nums[k] != nums[k+1]) return nums[k];
        }
        
        return nums[nums.size() - 1];
    }
};