#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};  // UP, RIGHT, DOWN, LEFT
    int dy[4] = {0, 1, 0, -1};
    std::map<int, std::vector<int>> street_dir;

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 각 거리 타입이 연결하는 방향 정의
        street_dir[1] = {LEFT, RIGHT};
        street_dir[2] = {UP, DOWN};
        street_dir[3] = {LEFT, DOWN};
        street_dir[4] = {RIGHT, DOWN};
        street_dir[5] = {LEFT, UP};
        street_dir[6] = {RIGHT, UP};
        
        // 방문 체크
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // BFS: (x, y, 들어온 방향)
        queue<tuple<int, int, int>> q;
        
        // 시작점에서 가능한 두 방향 모두 탐색
        for (int dir : street_dir[grid[0][0]]) {
            q.push({0, 0, dir});
        }
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [x, y, entrance] = q.front();
            q.pop();
            
            // 목적지 도달
            if (x == m - 1 && y == n - 1) {
                return true;
            }
            
            // 현재 셀에서 나갈 방향 계산 (들어온 방향의 반대)
            int exit_dir = -1;
            for (int dir : street_dir[grid[x][y]]) {
                if (dir != entrance) {
                    exit_dir = dir;
                    break;
                }
            }
            
            // 다음 셀 좌표
            int nx = x + dx[exit_dir];
            int ny = y + dy[exit_dir];
            
            // 범위 체크
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
                continue;
            }
            
            // 다음 셀이 현재 방향으로 연결될 수 있는지 확인
            // 다음 셀이 받아들일 수 있는 방향은 (exit_dir + 2) % 4 (반대 방향)
            int expected_entrance = (exit_dir + 2) % 4;
            if (street_dir[grid[nx][ny]][0] == expected_entrance || 
                street_dir[grid[nx][ny]][1] == expected_entrance) {
                visited[nx][ny] = true;
                q.push({nx, ny, expected_entrance});
            }
        }
        
        return false;
    }
};