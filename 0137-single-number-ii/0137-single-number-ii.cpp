class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int ret = nums[nums.size() - 1];

        for(int k = 1; k < nums.size(); k+=3){
            if(nums[k] != nums[k-1]) return nums[k-1];
        }

        return ret;
    }
};