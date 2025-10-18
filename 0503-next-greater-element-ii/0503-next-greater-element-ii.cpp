class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::stack<int> nums_idx;
        int size = nums.size();
        std::vector<int> ans(size, -1);

        for(int k=0; k < size; k++){
            nums.emplace_back(nums[k]);
        }

        nums_idx.emplace(0);

        for(int k=1; k < nums.size(); k++){

            while(!nums_idx.empty() && nums[k] > nums[nums_idx.top()]){
                ans[nums_idx.top() % size] = nums[k];
                nums_idx.pop();
            }

            nums_idx.emplace(k);
        }

        return ans;
    }
};