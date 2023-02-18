class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int diff = fabs(nums[0] + nums[1] + nums[2] - target);
        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<nums.size(); i++){
            for(int j= i + 1; j<nums.size(); j++){
                int idx = j+1;
                if(idx < nums.size()){
                    int val = nums[i] + nums[j] + nums[idx];
                    while(val <= target + diff){
                        if((val > target - diff) && (val < target + diff)){
                            diff = abs(val - target);
                            ans = val;
                        }
                        if(idx + 1 < nums.size()){
                            val += nums[idx + 1] - nums[idx++];
                        }else break;
                    }
                }
            }
        }
        return ans;
    }
};