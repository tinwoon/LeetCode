class Solution {
public:

    //dp[st][length] => st 부터 시작하고 길이가 length
    std::vector< std::vector<int> > dp;
    int max_size = 0;
    std::string ans;

    void init(string s){
        dp.assign(s.size(), std::vector<int>(s.size() + 1, 0));
        for(int k=0; k<s.size(); k++){
            dp[k][1] = 1;
        }
        ans = s[0];
    }

    string longestPalindrome(string s) {
        init(s);

        for(int length = 2; length <= s.size(); length++){
            for(int st=0; st + length <= s.size(); st++){
                if(s[st] == s[st + length - 1] && dp[st+1][length - 2] != -1){
                    dp[st][length] = dp[st + 1][length - 2] + 1;
                    if(dp[st][length] > max_size) ans = s.substr(st, length);
                }else dp[st][length] = -1;
            }
        }
        
        return ans;
    }
};