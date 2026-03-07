class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::vector<int> ans;
        std::sort(nums.begin(), nums.end());

        auto start = nums.begin();
        auto end = std::upper_bound(start, nums.end(), *start);
        int size = (int)(nums.size())/3;

        do{
            if(std::distance(start, end) >  size){
                ans.emplace_back(*start);
            }
            start = end;
            end = std::upper_bound(start, nums.end(), *start);
        }while(start != nums.end());

        return ans;   
    }
};