class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int start = 0, end = 0, ans = 1;
        long long sum = 0;

        for(; end < nums.size(); end++){
            sum += nums[end];

            while((long long)((long long)(end - start + 1) * (long long)nums[end]) > (long long)((long long)k + sum)){
                sum -= nums[start++];
            }

            ans = std::max(ans, end - start + 1);
        }

        return ans;
    }
};