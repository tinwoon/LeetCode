class Solution {
public:
    void append_zero(string& a, string& b){
        int v = a.size() - b.size();
        std::string str = "";
        if(v < 0){
            while(v++){
                str += '0';
            }
            a = str + a;
        }else if(v > 0){
            while(v--){
                str += '0';
            }
            b = str + b;
        }
    }
    
    string addBinary(string a, string b) {
        std::string ans = "";
        int upper_f = 0;
        append_zero(a,b);
        
        for(int k = (a.size() - 1); k >= 0; k--)
        {
            if((a[k] - '0') + (b[k] - '0') + upper_f >= 2){
                ans.push_back(a[k] + b[k] + upper_f - '0' - 2);
                upper_f = 1;
            }else {
                ans.push_back(a[k] + b[k] + upper_f - '0');
                upper_f = 0;
            }
        }
        std::reverse(ans.begin(), ans.end());
        
        return upper_f ? "1" + ans : ans;
    }
};