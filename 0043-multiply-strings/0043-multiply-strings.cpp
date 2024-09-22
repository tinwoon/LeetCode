class Solution {
public:
    string adding(string num1, string num2){
        if(num1.size() > num2.size()) std::swap(num1, num2);
        int rounding = 0;
        
        string ret = num2;
        
        for(int k = 0; k < num1.size(); k++){
            rounding += (ret[k] - '0') + (num1[k] - '0');
            ret[k] = (rounding%10 + '0');
            rounding /= 10;
        }
        
        int idx = num1.size();
        
        while(rounding != 0 && idx < num2.size()){
            rounding += (ret[idx] - '0');
            ret[idx++] = (rounding%10 + '0');
            rounding /= 10;
        }
        
        if(rounding) ret.push_back(rounding + '0');
        
        return ret;
    }
    
    string multiply(string num1, string num2) {
        string ret = "0";
        if(num1.size() > num2.size()) std::swap(num1, num2);
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        
        for(int i = 0; i < num1.size(); i++){
            int rounding_up = 0;
            string merge_multiply = num2;
            
            for(int j=0; j < num2.size(); j++){
                int multiple_v = ((num1[i] - '0') * (num2[j] - '0')) + rounding_up;
                rounding_up = multiple_v/10;
                
                merge_multiply[j] = (multiple_v%10) + '0';
            }
            if(rounding_up) merge_multiply.push_back(rounding_up + '0');
            
            for(int k=0; k < i; k++){
                merge_multiply = '0' + merge_multiply;
            }
            
            ret = adding(ret, merge_multiply);
        }
        
        std::reverse(ret.begin(), ret.end());
        
        return ret[0] == '0' ? "0" : ret;
    }
};