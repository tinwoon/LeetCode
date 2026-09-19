class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool contain_one = false;

        for(int k=0; k < nums.size(); k++){
            if(nums[k] == 1){
                contain_one = true;
            }else if(nums[k] > nums.size() || nums[k] <= 0){
                nums[k] = 1;
            }
        }

        if(!contain_one) return 1;

        for(int k=0; k < nums.size(); k++){
            if(abs(nums[k]) <= nums.size()){
                nums[abs(nums[k]) - 1] = -1 * abs(nums[abs(nums[k]) - 1]);
            }
        }

        for(int k=0; k < nums.size(); k++){
            if(nums[k] > 0) return k + 1;
        }

        return nums.size() + 1;
    }
};