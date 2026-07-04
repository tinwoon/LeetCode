class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        for(int k=1; k < nums.size() && k + 1 < nums.size(); k+=2){
            std::swap(nums[k], nums[k+1]);
        }
    }
};