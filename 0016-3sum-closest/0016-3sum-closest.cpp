class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         sort(nums.begin(),nums.end());
        int maxsum=1000000000;
        for(int i=0;i<nums.size()-2;i++)
        {
          int sum=nums[i];
          int j=i+1;
          int k=nums.size()-1;
          while(j<k)
          {
            sum=nums[i]+nums[j]+nums[k];
            if(sum==target)
            {
                return target;
            }
            if(abs(sum-target)<abs(maxsum-target))
            {
                maxsum=sum;
            }
            if(sum>target)
            {
                k--;
            }
            else if(sum<target)
            {
                j++;
            }
          }
        }
        return maxsum;
    }
};