class Solution {
public:
    int minDistance(string word1, string word2) {
        std::vector< std::vector<int> > data(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
        
        int m_size = std::max(word1.size(), word2.size());
        
        for(int k=0; k <= m_size; k++){
            if(k <= word1.size()) data[k][0] = k;
            if(k <= word2.size()) data[0][k] = k;
        }
        
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i - 1] == word2[j - 1]){
                    data[i][j] = data[i-1][j-1];
                }else{
                    data[i][j] = std::min({data[i-1][j], data[i-1][j-1], data[i][j-1]}) + 1;
                }
            }
        }
        
        return data[word1.size()][word2.size()];
    }
};