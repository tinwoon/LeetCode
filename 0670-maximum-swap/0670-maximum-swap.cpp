class Solution {
public:
    int maximumSwap(int num) {
        if(num < 10) return num;

        std::string num_s = to_string(num);
        std::string sort_num = num_s;

        std::sort(sort_num.begin(), sort_num.end(), std::greater<char>());

        for(int k=0; k < num_s.size(); k++){
            if(sort_num[k] != num_s[k]){
                int s_idx = std::distance(num_s.begin(), std::find(num_s.begin() + k, num_s.end(), sort_num[k]));

                std::swap(num_s[k], num_s[s_idx]);
                break;
            }
        }

        return stoi(num_s);
    }
};