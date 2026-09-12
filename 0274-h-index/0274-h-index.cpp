class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());

        int ans = 0;

        for(int i = 0; i < citations.size(); i++){
            ans = std::max(ans, std::min((int)citations.size() - i, citations[i]));
        
        }

        return ans;
    }
};