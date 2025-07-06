class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left_sum = 0;
        int right_sum = std::accumulate(nums.begin() + 1, nums.end(), 0);

        for(int k=0; k < nums.size(); k++){
            printf("%d, %d\n", left_sum, right_sum);

            if(left_sum == right_sum) return k;

            if(nums.size() - 1 != k){
                left_sum += nums[k];
                right_sum -= nums[k+1];
            }
        }

        return -1;
    }
};