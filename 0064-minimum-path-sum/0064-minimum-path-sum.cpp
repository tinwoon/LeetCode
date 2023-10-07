class Solution {
public:
    
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};
    int N, M;
    std::vector< std::vector<int> > weight;
    
    int calculate(std::vector< std::vector<int> >& grid){
        weight[0][0] = grid[0][0];
        std::priority_queue< std::tuple<int,int,int> > pq;
        pq.emplace(std::make_tuple(weight[0][0] * -1, 0, 0));
        
        while(!pq.empty()){
            int x, y, cost;
            std::tie(cost, x, y) = pq.top();
            pq.pop();
            cost *= -1;
            
            if(x == N-1 && y == M-1){
                return cost;
            }
            
            if(cost > weight[x][y]) continue;
            
            for(int k = 0; k < 2; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(nx < N && ny < M){
                    if(weight[nx][ny] > cost + grid[nx][ny]){
                        weight[nx][ny] = cost + grid[nx][ny];
                        pq.emplace(std::make_tuple(weight[nx][ny] * -1, nx, ny));
                    }
                }
            }
        }
        
        return -1;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        weight.assign(N, std::vector<int>(M, INT_MAX));
        return calculate(grid);
    }
};