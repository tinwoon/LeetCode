class Solution {
public:
    int max_len = 0;
    
    int max_size(int i, int j, vector<vector<char>>& matrix){
        return std::min(matrix.size() - i, matrix[i].size() - j);
    }
    
    int calculate(int i, int j, vector<vector<char>>& matrix){
        int m_len = max_size(i,j,matrix);
        int ret = 0;
        
        if(m_len < max_len) return 0;
        
        for(int k=1; k <= m_len; k++){
            bool is_square = true;
            
            for(int l=0; l < k; l++){
                if((matrix[i+k-1][j+l] == '0') || (matrix[i+l][j+k-1] == '0')){
                    is_square = false;
                    break;
                }
            }
            
            ret = (is_square ? (k * k) : ret);
            
            if(is_square){
                max_len = std::max(max_len, k);
            } else break;
        }
        
        return ret;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        
        for(int i=0; i < matrix.size(); i++){
            for(int j=0; j < matrix[i].size(); j++){
                ans = std::max(ans, calculate(i,j,matrix));
            }
        }
        
        return ans;
    }
};