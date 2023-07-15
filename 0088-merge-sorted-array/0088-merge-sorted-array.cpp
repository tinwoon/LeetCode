class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> ans;
        
        int i = 0, j = 0;
        while(i < m && j < n){
            if(nums1[i] < nums2[j]) ans.emplace_back(nums1[i++]);
            else ans.emplace_back(nums2[j++]);
        }
        for(; i < m; i++){
            ans.emplace_back(nums1[i]);
        }
        for(; j < n; j++){
            ans.emplace_back(nums2[j]);
        }
        nums1 = ans;
    }
};