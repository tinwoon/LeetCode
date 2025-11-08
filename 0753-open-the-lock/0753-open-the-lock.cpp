class Solution {
public:

    bool visited[10][10][10][10];

    int merge(int* point_x){
        return point_x[0] + 10 * point_x[1] + 100 * point_x[2] + 1000 * point_x[3];
    }

    bool same_target(int v, std::string target){
        std::string form = std::format("{:04}", v);

        return form == target;
    }

    int openLock(vector<string>& deadends, string target) {

        if(std::count(deadends.begin(), deadends.end(), "0000")) return -1;

        std::queue< std::pair<int, int> > q;

        visited[0][0][0][0] = true;
        q.emplace(std::make_pair(0, 0));

        for(int k=0; k < deadends.size(); k++){
            visited[deadends[k][3] - '0'][deadends[k][2] - '0'][deadends[k][1] - '0'][deadends[k][0] - '0'] = true;
        }
        
        while(!q.empty()){
            int lock = q.front().first, count = q.front().second;
            int x[4] = {0,0,0,0};
            int nums = 4;

            q.pop();

            if(same_target(lock, target)) return count;

            while(lock){
                x[4 - (nums--)] = lock % 10;
                lock /= 10;
            }

            for(int k=0; k < 4; k++){
                int px[4], mx[4];
                
                memcpy(px, x, 4 * sizeof(int));
                memcpy(mx, x, 4 * sizeof(int));
                
                px[k] = px[k] + 1 < 10 ? (px[k] + 1) : 0;
                mx[k] = mx[k] - 1 >= 0 ? (mx[k] - 1) : 9;

                if(!visited[px[0]][px[1]][px[2]][px[3]]){
                    q.emplace(std::make_pair(merge(px), count+1));
                    visited[px[0]][px[1]][px[2]][px[3]] = true;
                }

                if(!visited[mx[0]][mx[1]][mx[2]][mx[3]]){
                    q.emplace(std::make_pair(merge(mx), count+1));
                    visited[mx[0]][mx[1]][mx[2]][mx[3]] = true;
                }
            }
        }

        return -1;
    }
};