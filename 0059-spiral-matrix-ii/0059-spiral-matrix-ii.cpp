class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<vector<int>> generateMatrix(int n) {
        std::vector< std::vector<int> > matrix(n, std::vector<int>(n,0));
        
        int fill_s = 1;
        int dir = 0;
        int value = 1;
        matrix[0][0] = value;
        int x = 0, y = 0;
        
        while(fill_s != n*n){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx >=0 && nx < n && ny >= 0 && ny < n && !matrix[nx][ny]){
                matrix[x = nx][y = ny] = ++value;
                fill_s++;
            }else{
                dir = (dir + 1)%4;
            }
        }
        return matrix;
    }
};