class Solution {
public:
    std::vector< std::vector<int> > dp;
    std::vector< std::vector<int> > trngl;
    
    int calculate(int level, int j){
        if(dp[level][j] != INT_MAX) return dp[level][j];
        
        return dp[level][j] = std::min(calculate(level + 1, j), calculate(level + 1, j+1)) + trngl[level][j];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        dp = trngl = triangle;
        
        for(int idx = 0; idx < dp.size() - 1; idx++){
            std::fill(dp[idx].begin(), dp[idx].end(), INT_MAX);
        }
        
        return calculate(0,0);
    }
};