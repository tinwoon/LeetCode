class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1;
        int least = std::min(height[start], height[end]);
        int ans = least * (end - start);
        
        while(start < end){
            
            //start가 큰 경우로 end를 이동시켜야한다.
            if(height[start] > height[end]){
                if(height[end] < height[--end]){
                    ans = std::max(ans, (end - start) * (height[start] < height[end] ? height[start] : height[end]) );
                }
            //end가 start보다 큰 경우로 start를 이동시켜야한다.
            }else if(height[start] < height[end]){
                if(height[start] < height[++start]){
                    ans = std::max(ans, (end - start) * (height[start] < height[end] ? height[start] : height[end]) );
                }
                
            //둘이 같은 경우로 start, end를 한칸씩 이동하면서 큰게 먼저 나온 경우로 이동시켜야한다.
            }else{
                if(height[start + 1] > height[end - 1] && height[start + 1] > height[start]){
                    ans = std::max(ans, (end - ++start) * height[end]);
                } 
                else if(height[start + 1] < height[end - 1] && height[start] < height[end - 1]){
                    ans = std::max(ans, (--end - start) * height[start]);
                } 
                else{
                    ans = std::max(ans, (--end - ++start) * height[start]);
                }
            }
        }
        
        return ans;
    }
};