class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int Mat_M = (int)matrix.size();
        
        for(int i = 0; i < (Mat_M/2); i++){
            for(int j = 0; j < Mat_M - 1 - (2*i); j++){
                int top = matrix[i][j + i];
                matrix[i][j + i] = matrix[Mat_M - 1 - i - j][i];
                matrix[Mat_M - 1 - i - j][i] = matrix[Mat_M - 1 - i][Mat_M - 1 - j - i];
                matrix[Mat_M - 1 - i][Mat_M - 1 - j - i] = matrix[j + i][Mat_M - 1 - i];
                matrix[j + i][Mat_M - 1 - i] = top;
            }
        }
        
        return;
    }
};