class Solution {
public:
    bool is_ok(vector<int>& nums, int threshold, int div){
        int s = 0;

        for(int k=0; k < nums.size(); k++){
            s += nums[k]/div + (bool)(nums[k]%div);
        }

        return s <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        std::sort(nums.begin(), nums.end());

        int ans = 1000000;
        int left = 1;
        int right = 1000000;

        while(left < right){
            int mid = (left + right)/2;

            if(is_ok(nums, threshold, mid)){
                ans = std::min(ans, mid);
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return ans;
    }
};