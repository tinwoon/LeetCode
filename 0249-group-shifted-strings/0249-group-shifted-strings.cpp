class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        //자리 수가 같고, 이름이 같으면 된다.
        std::map<std::string, std::vector<std::string> > ans;
        std::vector< std::vector<std::string> > ret;

        
        for(int i=0; i < strings.size(); i++){
            std::string diff = "F";
            for(int j=1; j < strings[i].size(); j++){
                int diff_i = strings[i][j] - strings[i][j-1];
                if(diff_i < 0) diff_i += (int)26;
                
                diff += (char)diff_i;
            }
            
            ans[diff].emplace_back(strings[i]);
        }

        for(auto itr = ans.begin(); itr != ans.end(); itr++){
            ret.emplace_back(itr->second);
        }

        return ret;
    }
};