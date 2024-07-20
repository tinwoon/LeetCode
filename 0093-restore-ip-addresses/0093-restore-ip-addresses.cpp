class Solution {
public:
    std::vector<string> ret;
    void calculate(int level, string &s, std::vector<int> data){
        
        if(data.size() >= 5) return;
        
        if(level == s.size()){
            if(data.size() != 4) return;
            
            std::string ip;
            for(int k=0; k < 3; k++){
                ip += to_string(data[k]) + ".";
            }
            ip += to_string(data[3]);
            
            ret.emplace_back(ip);
            return;
        }
        
        if((data.size()) && (data[data.size()-1]) && (data[data.size() - 1]*10 + (s[level] - '0') <= 0xFF)){
            //data 뒤에 숫자 넣을지
            data[data.size() - 1] = data[data.size() - 1]*10 + (s[level] - '0');
            calculate(level + 1, s, data);
            data[data.size() - 1] /= 10;
        }
        
        //아니면 data 끝내고 새로 push 할지
        data.emplace_back(s[level] - '0');
        calculate(level + 1, s, data);
        return;
    }
    
    vector<string> restoreIpAddresses(string s) {
        calculate(0, s, std::vector<int>());
        
        return ret;
    }
};