class Solution {
public:
    std::vector<int> square;
    int ans = INT_MAX;
    
    void calculate(int remain, int level){
        if(level >= ans) return;
        
        if(remain <= 0){
            if(!remain){
                ans = std::min(ans, level);
            }
            return;
        }
        
        for(int k = square.size() - 1; k >= 0; k--){
            calculate(remain - square[k], level+1);
        }
    }
    
    int numSquares(int n) {
        for(int k=1; k * k <= n; k++){
            square.emplace_back(k*k);
        }
        
        calculate(n, 0);
        return ans;
    }
};