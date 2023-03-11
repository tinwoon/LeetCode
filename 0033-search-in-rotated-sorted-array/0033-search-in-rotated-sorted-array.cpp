class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = -1;
        for(int i=0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                size = i;
                break;
            }
        }
        std::sort(nums.begin(), nums.end());
        auto idx = std::find(nums.begin(), nums.end(), target);
        if(idx == nums.end()) return -1;
        return ((idx - nums.begin()) + size + 1) % (nums.size());
    }
};