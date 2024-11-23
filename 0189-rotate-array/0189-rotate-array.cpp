class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        std::vector<int> store = std::vector<int>(nums.end() - (k % nums.size()), nums.end());
        store.insert(store.end(), nums.begin(), nums.end() - (k % nums.size()));
        nums = store;
    }
};