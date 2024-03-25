class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::vector<int> new_nums;
        for(int k=0; k < nums.size(); k++){
            if(nums[k] != val) new_nums.emplace_back(nums[k]);
        }
        nums = new_nums;
        return nums.size();
    }
};