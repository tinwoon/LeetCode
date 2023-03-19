class Solution {
public:
    //재귀 순환으로 풀이
    //이전과 일치하지 않는 새로운 숫자가 발견될 때 container에 prv를 넣어줘야 함을
    //고려하지 못함(line 20)
    string validate(string prs, int n){
        if(n == 1) return prs;
        
        std::string ans = "";
        std::vector<char> container; 
        
        char prv = prs[0];
        container.emplace_back(prv);
        for(int idx = 1; idx < prs.size(); idx++){
            if(prv != prs[idx]){
                prv = prs[idx];
                ans.push_back((container.size()) + '0');
                ans.push_back(container.back());
                container.clear();
                container.emplace_back(prv);
            }else{
                container.emplace_back(prs[idx]);
            }
        }
        
        ans.push_back((container.size()) + '0');
        ans.push_back(container.back());
                
        return validate(ans, n-1);
    }
    
    string countAndSay(int n) {
        return validate("1", n);
    }
};