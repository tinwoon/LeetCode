class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            std::map<int,int> odd, even;

            for (int j = i; j < nums.size(); j++) {
                auto& c = (nums[j] & 1) ? odd : even;
                c[nums[j]]++;

                if (odd.size() == even.size()) {
                    ans = std::max(ans, j - i + 1);
                }
            }
        }

        return int(ans);
    }
};