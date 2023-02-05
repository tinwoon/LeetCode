class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, idx = 0;
        std::vector< std::string > symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        std::vector<int> data = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        for(int k=0; k<symbol.size(); k++){
            
            bool flag = true;
            for(int sz = 0; sz < symbol[k].size(); sz++){
                if(symbol[k][sz] != s[idx+sz]) flag = false;
            }
            if(flag){
                ans += data[k];
                idx += symbol[k--].size();
            } 
        }
        return ans;
    }
};