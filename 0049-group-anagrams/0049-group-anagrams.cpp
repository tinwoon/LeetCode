class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //key : vector<26> : 알파벳의 개수
        std::map< std::vector<int>, std::vector< std::string > > ans;
        std::vector< std::vector< std::string > >  ret;
        
        for(int i=0; i < strs.size(); i++){
            std::vector<int> key(26,0);
            
            for(int j=0; j < strs[i].size(); j++){
                key[strs[i][j] - 'a']++;
            }
            
            if(!ans.count(key)){
                ans.insert(std::pair<std::vector<int>, std::vector<std::string>>(key, {strs[i]}));
            }else ans[key].emplace_back(strs[i]);
        }
        
        
        for(auto itr = ans.begin(); itr != ans.end(); itr++){
            ret.emplace_back((*itr).second);
        }
        
        return ret;
    }
};