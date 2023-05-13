class Solution {
public:
    vector<int>  gnums;
    vector<bool> visited;
    
    bool dfs(int idx){
        if(idx == gnums.size() - 1) return true;
        visited[idx] = true;
        bool ret = false;
        
        for(int k = 1; k <= gnums[idx]; k++){
            int n_idx = idx + k;
            if(n_idx < gnums.size()){
                if(!visited[n_idx]) ret = dfs(n_idx);
                if(ret) return true;
            }
        }
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        gnums = nums;
        visited.assign(nums.size(), false);
        
        return nums.size() == 1 ? true : dfs(0);
    }
};