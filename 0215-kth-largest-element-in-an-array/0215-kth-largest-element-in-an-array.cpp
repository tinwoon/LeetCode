class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
        
        for(int idx = 0; idx < k; idx++){
            pq.emplace(nums[idx]);
        }
        
        for(int idx = k; idx < nums.size(); idx++){
            if(pq.top() <= nums[idx]){
                pq.pop();
                pq.emplace(nums[idx]);
            }
        }
        
        return pq.top();
    }
};