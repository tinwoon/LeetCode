class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size() <= 2) return 0;
        int p_start = arr[0] < arr[1] ? 0 : INT_MAX;
        int ans = 0;

        for(int k=1; k < arr.size() - 1; k++){
            if(arr[k-1] > arr[k] && arr[k] <= arr[k+1]){
                if(p_start < k){
                    ans = std::max(ans, k - p_start + 1);
                }
            }

            if(arr[k-1] >= arr[k] && arr[k] < arr[k+1]){
                p_start = k;
            }

            if(arr[k] == arr[k+1]){
                p_start = INT_MAX;
            }
        }

        if(arr[arr.size() - 2] > arr[arr.size() - 1]){
            ans = std::max(ans, (int)(arr.size()) - p_start);
        }

        return ans;
    }
};