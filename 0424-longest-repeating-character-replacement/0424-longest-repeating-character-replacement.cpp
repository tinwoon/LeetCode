class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() == 1) return 1;

        std::map<char, int> m;
        int start = 0, end = 1, ans = 1;
        
        m[s[start]]++;

        while(end <= s.size()){
            int max_v = -1;
            int sum_wtht_t_max = 0;

            for(const auto& pair : m){
                if(max_v < pair.second){
                    max_v = pair.second;
                }
                sum_wtht_t_max += pair.second;
            }

            sum_wtht_t_max -= max_v;

            if(sum_wtht_t_max <= k){
                ans = std::max(ans, end - start);
                m[s[end++]]++;
            }else{
                m[s[start++]]--;
            }
        }

        return ans;
    }
};