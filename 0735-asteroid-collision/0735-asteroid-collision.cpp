class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> positive_idx;

        for(int k = asteroids.size() - 1; k >= 0; k--){
            if(asteroids[k] > 0) positive_idx.emplace_back(k);
        }

        for(int start_idx = 0; start_idx < positive_idx.size(); start_idx++){
            
            auto start = asteroids.begin() + positive_idx[start_idx];
            auto end = std::find_if(start + 1, asteroids.end(), [](int num){return num > 0;});
            auto idx = start + 1;
            int distance = std::distance(start, end) - 1;
            
            for(; distance != 0; idx++){
                if(*start + *idx < 0){
                    asteroids.erase(start);
                    break;
                }else if(*start + *idx > 0){
                    asteroids.erase(idx--);
                    distance--;
                }else{
                    asteroids.erase(idx);
                    asteroids.erase(start);
                    break;
                }
            }
        }

        return asteroids;
    }
};