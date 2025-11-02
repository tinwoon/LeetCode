class Solution {
public:
    inline bool is_visited(int pos, int spd, std::vector< std::vector<int> > &visited){
        return std::count(visited[pos].begin(), visited[pos].end(), spd);
    }
    
    int racecar(int target) {
        int ans = INT_MAX;
        //visited[pos] = {first spd, second spd};
        std::vector< std::vector<int> > visited(10001, std::vector<int>(0,0));
        std::queue< std::tuple<int, int, int> > q;

        visited[0].emplace_back(1);
        q.emplace(std::make_tuple(0, 1, 0));

        while(!q.empty()){
            int pos, spd, count;
            std::tie(pos, spd, count) = q.front();
            q.pop();

            if(pos == target){
                ans = std::min(ans, count);
                continue;
            }

            if(count > ans) continue;

            for(int k=0; k < 2; k++){
                int n_pos, n_spd;
                if(k==0){
                    n_pos = pos + spd;
                    n_spd = spd * 2;
                }else{
                    n_pos = pos;
                    n_spd = ((spd > 0) ? -1 : 1);
                }

                if(n_pos >= 1 && n_pos <= 10000 && !is_visited(n_pos, n_spd, visited)){
                    visited[n_pos].emplace_back(n_spd);
                    q.emplace(std::make_tuple(n_pos, n_spd, count+1));
                }
            }
        }
        
        return ans;
    }
};