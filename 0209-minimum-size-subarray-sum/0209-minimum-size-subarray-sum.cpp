class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int ans = INT_MAX;
        int sum = nums[left];
        
        while(1){
            if((ans <= right - left + 1) || (sum >= target)){
                if(sum >= target) ans = std::min(ans, right - left + 1);
                sum -= nums[left];
                left++;
                if(left >= nums.size()) break;
            }else if(sum < target){
                right++;
                if(right >= nums.size()) break;
                sum += nums[right];
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};