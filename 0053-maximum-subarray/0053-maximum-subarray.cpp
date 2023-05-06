class Solution {
public:
    int calculate(vector<int>&nums, int left, int mid, int right){
       
        if(left > right) return INT_MIN;
        if(left == right) return nums[left];
        
        int left_sum = INT_MIN, right_sum = INT_MIN;
        int ret = INT_MIN;
        
        int sum = 0;
        //left
        for(int k = mid; k >= left; k--){
            if(left_sum < (sum += nums[k])) left_sum = sum;
        }
        
        sum = 0;
        //right
        for(int k = mid; k <= right; k++){
            if(right_sum < (sum += nums[k])) right_sum = sum;
        }
               
        ret = max({left_sum, right_sum, left_sum + right_sum - nums[mid]});
        
        return max({ret, 
                    calculate(nums, left, (left + mid - 1)/2 ,mid - 1), 
                   calculate(nums, mid + 1, (mid + 1 + right)/2 ,right)});
    }
    
    int maxSubArray(vector<int>& nums) {
        return calculate(nums, 0, (nums.size() - 1) / 2 ,nums.size() - 1);
    }
};