class Solution {
public:
    std::vector<int> words_mask;
    int ans = 0;
    
    static bool compare(string a, string b){
        return a.length() > b.length();
    }
    
    int maxProduct(vector<string>& words) {
        std::sort(words.begin(), words.end(), compare);
        words_mask.assign(words.size(), 0);
        
        for(int i=0; i < words.size(); i++){
            for(int j=0; j < words[i].size(); j++){
                words_mask[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        
        for(int i=0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                if(!(words_mask[i] & words_mask[j])){
                    ans = std::max(ans, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        
        return ans;
    }
};