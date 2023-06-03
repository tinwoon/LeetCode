class Solution {
public:
    
    std::vector<int> dp;
    int N;
    
    int calculate(int node){
        if(node == 0) return 1;
        if(node < 0) return 0;
        if(dp[node]) return dp[node];
        
        return dp[node] = calculate(node - 2) + calculate(node - 1);
    }
    
    int climbStairs(int n) {
        N = n;
        dp.assign(N + 1,0);
        return calculate(N);
    }
};