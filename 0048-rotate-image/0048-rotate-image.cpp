class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int Mat_M = (int)matrix.size();
        
        for(int i = 0; i < (Mat_M/2); i++){
            for(int j = 0; j < Mat_M - 1 - (2*i); j++){
                int top = matrix[i][j + i];
                printf("1 : %d\n", top);
                
                matrix[i][j + i] = matrix[Mat_M - 1 - i - j][i];
                printf("2 : %d\n", matrix[i][j + i]);
                
                matrix[Mat_M - 1 - i - j][i] = matrix[Mat_M - 1 - i][Mat_M - 1 - j - i];
                printf("3 : %d\n", matrix[Mat_M - 1 - i - j][i]);
                
                matrix[Mat_M - 1 - i][Mat_M - 1 - j - i] = matrix[j + i][Mat_M - 1 - i];
                printf("4 : %d\n", matrix[Mat_M - 1 - i][Mat_M - 1 - j - i]);
                
                matrix[j + i][Mat_M - 1 - i] = top;
                printf("5 : %d\n\n", matrix[j + i][Mat_M - 1 - i]);
            }
            for(int a = 0; a < Mat_M; a++){
                for(int b = 0; b < Mat_M; b++){
                    printf("%d ", matrix[a][b]);
                }
                printf("\n");
            }
        }
        
        return;
    }
};