class Solution {
public:
    int calculate(std::vector<int>& nums){
        
        if(nums.size() <= 2) return nums.size();
        
        for(int k = 2; k < nums.size(); k++){
            if(nums[k] == nums[k - 1] && nums[k] == nums[k-2]){
                nums.erase(nums.begin() + k);
                k--;
            }
        }
        
        return nums.size();
    }
    
    int removeDuplicates(vector<int>& nums) {
        return calculate(nums);
    }
};