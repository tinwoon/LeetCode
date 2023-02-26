class Solution {
public:
    
    std::vector<std::string> ret;
    
    void calculate(std::string ans, int val, int n){
        if(ans.size() == n){
            if(val == 0) ret.emplace_back(ans);
            return;
        }
        
        //')'
        if(val > 0){
            calculate(ans + ')', val - 1, n);
        }
        //'('
        calculate(ans + '(', val + 1, n);
        
    }
    
    vector<string> generateParenthesis(int n) {
        std::string ans = "";
        calculate(ans, 0, 2*n);
        return ret;
    }
};