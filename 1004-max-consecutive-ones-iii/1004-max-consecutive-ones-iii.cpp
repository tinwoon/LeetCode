class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, ans = 0;

        while(end != nums.size()){
            if(k==0 && !nums[end]){
                k += (!nums[start++]);
            }
            else
            {
                k -= (!nums[end++]);
            }
            
            ans = std::max(ans, end - start);
        }

        return ans;
    }
};