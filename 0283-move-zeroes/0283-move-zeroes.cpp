class Solution {
public:
    int find_zero(vector<int>& nums){
        return std::distance(nums.begin(), std::find(nums.begin(), nums.end(), 0));
    }

    int find_not_zero(vector<int>& nums, int start){
        for(int k = start + 1; k < nums.size(); k++){
            if(nums[k]) return k;
        }

        return -1;
    }

    void moveZeroes(vector<int>& nums) {
        int zero_loc = 0;

        while((zero_loc = find_zero(nums)) < nums.size()){
            int not_zero_loc = find_not_zero(nums, zero_loc);

            if(not_zero_loc == -1) break;

            std::swap(nums[zero_loc], nums[not_zero_loc]);
        }
    }
};