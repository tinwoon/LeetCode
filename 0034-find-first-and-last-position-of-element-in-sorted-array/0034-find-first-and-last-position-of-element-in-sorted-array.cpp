class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto first = std::find(nums.begin(), nums.end(), target);
        if(first == nums.end()){
            return std::vector<int>{-1, -1};
        }
        auto second = std::upper_bound(nums.begin(), nums.end(), target);
        std::vector<int> ret;
        ret.emplace_back(first - nums.begin());
        ret.emplace_back(second - nums.begin() -1);
        
        return ret;
    }
};