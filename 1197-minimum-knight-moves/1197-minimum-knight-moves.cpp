class Solution {
public:
    int dx[8] = {-1,-2,-2,-1,1,2,2,1};
    int dy[8] = {2,1,-1,-2,-2,-1,1,2};

    int minKnightMoves(int x, int y) {
        std::queue< std::tuple<int, int, int> > q;
        std::set< std::pair<int, int> > visited;

        q.emplace(std::make_tuple(0, 0, 0));
        visited.emplace(std::make_pair(0,0));

        while(!q.empty()){
            int s_x, s_y, num;

            std::tie(s_x, s_y, num) = q.front();
            q.pop();

            if(s_x == x && s_y == y) return num;

            for(int k=0; k < 8; k++){
                int nx = s_x + dx[k];
                int ny = s_y + dy[k];

                if(!visited.count({nx, ny})){
                    if(nx >= -300 && nx <= 300 && ny >= -300 && ny <= 300 && abs(nx) + abs(ny) <= 300 && abs(nx) + abs(ny) >=0){
                        q.emplace(std::make_tuple(nx, ny, num+1));
                        visited.emplace(std::make_pair(nx, ny));
                    }
                }

            }
        }

        return -1;
    }
};