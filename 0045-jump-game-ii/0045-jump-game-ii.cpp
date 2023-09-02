class Solution {
public:
    int calculate(vector<int>& nums){
        
        std::queue< std::pair<int, int> > q;
        q.emplace(std::make_pair(0,0));
        
        std::vector<bool> visited(nums.size(), false);
        visited[0] = true;
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int idx = front.first;
            int jump = front.second;
            
            if(idx == (nums.size() - 1)) return jump;
            
            for(int i = idx + 1; i <= idx + nums[idx]; i++){
                if((i < nums.size()) && !visited[i]){
                    visited[i] = true;
                    q.emplace(std::make_pair(i, jump + 1));
                }
            }
            
        }
        
        return -1;
    }
    
    int jump(vector<int>& nums) {
        return calculate(nums);
    }
};