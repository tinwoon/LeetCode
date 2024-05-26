class Solution {
public:
    bool isPalindrome(string s) {
        std::vector<char> ret;
        
        for(int k=0; k <s.size(); k++){
            if(isalpha(s[k])){
                ret.emplace_back(tolower(s[k]));
            }
            if(isdigit(s[k])){
                ret.emplace_back(s[k]);
            }
        }
        
        if(ret.size() == 0) return true;
        
        for(int k = 0; k <= (ret.size() / 2); k++){
            if(ret[k] != ret[ret.size() - 1 - k]) return false;
        }
        
        return true;
    }
};