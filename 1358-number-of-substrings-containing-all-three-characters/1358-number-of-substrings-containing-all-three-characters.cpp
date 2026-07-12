class Solution {
public:
    int numberOfSubstrings(string s) {
        std::queue<int> a_loc, b_loc, c_loc;
        int ans = 0;
        
        for(int k=0; k < s.size(); k++){
            if(s[k] == 'a'){
                a_loc.emplace(k);
            }else if(s[k] == 'b'){
                b_loc.emplace(k);
            }else{
                c_loc.emplace(k);
            }
        }

        while(!a_loc.empty() && !b_loc.empty() && !c_loc.empty()){
            int min_v, max_v;

            min_v = std::min({a_loc.front(), b_loc.front(), c_loc.front()});
            max_v = std::max({a_loc.front(), b_loc.front(), c_loc.front()});

            ans += s.size() - max_v;

            if(min_v == a_loc.front()){
                a_loc.pop();
            }else if(min_v == b_loc.front()){
                b_loc.pop();
            }else{
                c_loc.pop();
            }
        }
        return ans;
    }
};