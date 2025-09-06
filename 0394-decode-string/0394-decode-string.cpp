class Solution {
public:
    std::string i_s;

    void converted(int num_find_idx, int number){
        std::string str = "";
        std::string rp_str = "";
        int n_num = 0;

        for(int s_idx = num_find_idx + 2; s_idx < i_s.size(); s_idx++){
            if(isdigit(i_s[s_idx])){
                n_num = n_num * 10 + (i_s[s_idx] - '0');
                if(s_idx + 1 < i_s.size() && !isdigit(i_s[s_idx + 1])){
                    converted(s_idx, n_num);
                    s_idx -= (std::to_string(n_num).length());
                    n_num = 0;
                }
            }else if(isalpha(i_s[s_idx])){
                str += i_s[s_idx];
            }else{ //']'
                for(int k=0; k < number; k++){
                    rp_str += str;
                }
                int num_length = std::to_string(number).length();
                i_s.replace(num_find_idx - num_length + 1, s_idx - num_find_idx + num_length, rp_str);

                break;
            }
        }

        return;
    }

    string decodeString(string s) {
        i_s = s;
        int number = 0;

        for(int num_find_idx = 0; num_find_idx < i_s.size(); num_find_idx++){
            if(isdigit(i_s[num_find_idx])){
                number = number * 10 + (i_s[num_find_idx] - '0');
                if(num_find_idx + 1 < i_s.size() && !isdigit(i_s[num_find_idx + 1])){
                    converted(num_find_idx, number);
                    num_find_idx -= (std::to_string(number).length());
                    number = 0;
                }
                
            }
        }

        return i_s;
    }
};