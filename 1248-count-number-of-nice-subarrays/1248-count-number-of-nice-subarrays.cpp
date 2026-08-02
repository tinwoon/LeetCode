class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        std::vector<int> odd_index;

        for(int i=0; i < nums.size(); i++){
            if(nums[i] % 2) odd_index.emplace_back(i);
        }

        for(int start = 0; start + k - 1 < odd_index.size(); start++){
            int end = start + k - 1;

            ans += (start == 0 ? odd_index[start] + 1 : odd_index[start] - odd_index[start - 1]) * (end == (odd_index.size() - 1) ? (nums.size() - odd_index[end]) : (odd_index[end + 1] - odd_index[end]));
        }

        return ans;
    }
};