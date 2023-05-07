class Solution {
public:
    
    //위, 오른쪽, 아래, 왼쪽
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    std::vector<int> ans;
    std::vector< std::vector<bool> > visited;
    
    void calculate(int i, int j, int dir, std::vector< std::vector<int> > &matrix){
        visited[i][j] = true;
        std::queue< std::tuple<int,int, int> > q;
        q.emplace(std::make_tuple(i,j,dir));
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int x = std::get<0>(front);
            int y = std::get<1>(front);
            int dir = std::get<2>(front);
            ans.emplace_back(matrix[x][y]);
            
            
            if((x + dx[dir] >=0) && (x + dx[dir] < matrix.size()) 
               && (y + dy[dir] >=0) && (y + dy[dir] < matrix[0].size())
               && (!visited[x + dx[dir]][y + dy[dir]])){
                visited[x + dx[dir]][y + dy[dir]] = true;
                q.emplace(std::make_tuple(x + dx[dir], y + dy[dir], dir));
            }else{
                for(int k=1; k<=3; k++){
                    int n_dir = (dir + k) % 4;
                    int nx = x + dx[n_dir];
                    int ny = y + dy[n_dir];
                    if((nx >=0) && (nx < matrix.size()) 
                        && (ny >=0) && (ny < matrix[0].size())
                        && (!visited[nx][ny])){
                        visited[nx][ny] = true;
                        q.emplace(std::make_tuple(nx, ny, n_dir));
                        break;
                    }
                }
            }
        }
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        visited.assign(matrix.size(), std::vector<bool>(matrix[0].size(), false));
        calculate(0,0,1,matrix);
        return ans;
    }
};