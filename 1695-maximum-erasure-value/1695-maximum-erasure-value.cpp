class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bool visited[10001] = {false, };
        int sum = nums[0];
        int ans = sum;
        int s = 0;, e = 1;

        while(e < nums.end()){
            if(!visited[e]){
                visited[e] = true;
                sum += nums[e];
                e++;

                ans = std::max(sum, ans);
            }else{
                visited[s] = false;
                sum -= nums[s];
                s--;
            }
        }

        return ans;
    }
};