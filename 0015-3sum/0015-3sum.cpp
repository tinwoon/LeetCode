class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        std::set< std::vector<int> > ans;
        std::vector< std::vector<int> > ret;
        
        std::sort(nums.begin(), nums.end());
        for(auto i = nums.begin(); i != nums.end(); i = std::upper_bound(i + 1,nums.end(),*i)){
            for(auto j = i + 1; j != nums.end(); j = std::upper_bound(j + 1,nums.end(),*j)){
                auto left = std::lower_bound(j+1, nums.end(), -1*(*i + *j));
                auto right = std::upper_bound(j+1, nums.end(), -1*(*i + *j));
                if(left != nums.end()){
                    for(;left != right; left++){
                        ans.emplace(std::vector<int>({*i, *j, *left}));
                    }
                }
            }
        }
        
        ret.assign(ans.begin(), ans.end());
        return ret;
    }
};