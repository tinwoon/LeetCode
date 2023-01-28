class Solution {
public:
    
    //1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
    std::vector< std::string > symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    std::vector<int> data = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    string intToRoman(int num) {
        std::string ans;
        
        while(num!=0){
            
            for(int k=0; k<13; k++){
                if(num / data[k]){
                    ans+= symbol[k];
                    num -= data[k];
                    break;
                }
            }
        }
        return ans;
    }
};