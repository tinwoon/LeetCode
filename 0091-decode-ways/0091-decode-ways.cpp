class Solution {
public:
    
    int numDecodings(string s) {
        if(s[0] == '0') return 0; 
        if(s.length() == 1) return 1; 
        
        std::vector<int> dp(s.length()+1,0); 
        
        dp[1] = dp[0] = 1;
        for(int i = 2; i <= s.length(); i++){
            int first = stoi(s.substr(i-1,1)); 
            int second = stoi(s.substr(i-2,2)); 

            if(first >= 1 && first <= 9) dp[i] += dp[i-1]; 
            if(second >= 10 && second <= 26) dp[i] += dp[i-2]; 
        }
        return dp[s.length()]; 
    }
};