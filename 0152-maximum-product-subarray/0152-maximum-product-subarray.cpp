class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];

            // 음수면 max/min 역할이 뒤집힘
            if (num < 0) {
                swap(curMax, curMin);
            }

            curMax = max(num, curMax * num);
            curMin = min(num, curMin * num);

            result = max(result, curMax);
        }

        return result;
    }
};