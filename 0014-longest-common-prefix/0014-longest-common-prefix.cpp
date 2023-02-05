class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string s = "";
        if(strs.size() == 1) return strs[0];
        for(int i=0; i <= strs[0].size(); i++){
            char prefix_c = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if((strs[j].size() <= i) || (strs[j][i] != prefix_c)) return s;
            }
            s += prefix_c;
        }
        return s;
    }
};