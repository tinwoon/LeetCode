//Date : 2023-03-26
//1. state of "i", Find some idx that more than height[i] from i+1 to height[final]
//2. In this, if find that height[i] >= height[idx], this can be left and right
//3. add a water height between left, right value;

class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        for(int i=0; i<height.size(); i++){
            if(height[i]){
                std::pair<int,int> R = {-1,0};
                for(int j = i+1; j < height.size(); j++){
                    if(height[j] > R.second){
                        R = {j, height[j]};
                        if(R.second >= height[i]) break;
                    }
                }
                
                if(R.first == -1) continue;
                
                int H = std::min(height[i], R.second);
                for(int idx = i + 1; idx < R.first; idx++){
                    ret += (H - height[idx]);
                }
                i = R.first - 1;
            }
        }
        return ret;
    }
};