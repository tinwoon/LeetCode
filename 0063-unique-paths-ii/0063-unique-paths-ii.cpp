class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int N = obstacleGrid.size(), M = obstacleGrid[0].size();
        std::vector< std::vector<long long> > map(N + 1, std::vector<long long>(M + 1, 0));
        map[N - 1][M] = 1;
        
        for(int i = obstacleGrid.size() - 1; i >= 0; i--){
            for(int j = obstacleGrid[0].size() - 1; j >= 0; j--){
                if(!obstacleGrid[i][j]) map[i][j] = map[i + 1][j] + map[i][j + 1];
            }
        }
        
        return map[0][0];
    }
};