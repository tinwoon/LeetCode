class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        
        for(int i=0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    int y = i, x = 0, max_col = INT_MAX;

                    while((y < matrix.size()) && matrix[y][j] == '1'){
                        x = j;
                        while((x + 1 < matrix[0].size()) && matrix[y][x+1] == '1'){
                            x++;
                        }
                        max_col = std::min(max_col, x - j + 1);
                        ans = std::max(ans, max_col * (y++ - i + 1));
                    }
                }
            }
        }

        return ans;
    }
};