class Solution {
public:
    int lengthOfLastWord(string s) {
        bool find_first_character = false;
        int first_idx = -1;
        for(int k = s.size() - 1; k >= 0; k--){
            if(find_first_character == true){
                if(s[k] == ' ') return first_idx - k;
            }else{
                if(s[k] != ' '){
                    find_first_character = true;
                    first_idx = k;
                }
            }
        }
        return first_idx + 1;
    }
};