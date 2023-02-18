class Solution {
public:
    std::map<char, std::string> mp = { {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8,"tuv"}, {9, "wxyz"}};
    
    std::vector<std::string>  ans = {};
    
    void calculate(string& digits, int level, std::string val){
        if(level == digits.size()){
            if(val.size()) ans.emplace_back(val);
            return;
        }
        //nums에 해당하는 알파벳들
        std::string nums = mp[digits[level] - '0'];
        
        for(int k=0; k < nums.size(); k++){
            calculate(digits, level+1, val + nums[k]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        calculate(digits, 0, "");
        return ans;
    }
};