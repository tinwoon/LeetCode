class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        std::vector< std::vector<int> > ans;
        //loc, height, input 여부
        std::priority_queue< std::tuple<int, int, bool> > pq;
        std::map<int, int> enable_height;                 // 수정 1: bool -> int (개수)
        std::priority_queue<int> possible_height;
        int prev_skyline_height = 0;
        
        for(int n=0; n < buildings.size(); n++){
            pq.emplace(std::make_tuple(buildings[n][0] * -1, buildings[n][2], true));
            pq.emplace(std::make_tuple(buildings[n][1] * -1, -buildings[n][2], false));  // 수정 4: 끝은 음수 높이
        }

        while(!pq.empty()){
            int loc, height;
            bool input;

            std::tie(loc, height, input) = pq.top();
            loc = loc * -1;
            height = std::abs(height);                    // 수정 4

            pq.pop();
            
            if(input){
                enable_height[height]++;                  // 수정 1
                possible_height.emplace(height);
            }else{
                enable_height[height]--;                  // 수정 1
            }

            while(!possible_height.empty() && enable_height[possible_height.top()] == 0){  // 수정 1, 2
                possible_height.pop();
            }    

            if(possible_height.empty()){
                ans.emplace_back(std::vector<int>{loc, 0});   // 수정 3: () -> {}
                prev_skyline_height = 0;
            }
            else if(possible_height.top() != prev_skyline_height){
                ans.emplace_back(std::vector<int>{loc, possible_height.top()});
                prev_skyline_height = possible_height.top();
            }
        }

        return ans;
    }
};