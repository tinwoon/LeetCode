class Solution {
public:
    std::stack<char> open;
    
    bool isValid(string s) {
        for(int k=0; k<s.size(); k++){
            if(s[k] == '(' || s[k] == '[' || s[k] == '{'){
                open.push(s[k]);
            }else{
                if(open.empty()) return false;
                if(s[k] == ')'){
                    if(open.top() != '(') return false;
                    open.pop();
                }else if(s[k] == ']'){
                    if(open.top() != '[') return false;
                    open.pop();
                }else if(s[k] == '}'){
                    if(open.top() != '{') return false;
                    open.pop();
                }
            }
        }
        return open.size() ? false : true;
    }
};