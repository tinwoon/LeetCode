class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for(int k=0; k < prices.size()-1; k++){
            if(prices[k] < prices[k+1]) ret += (prices[k+1] - prices[k]);
        }
        return ret;
    }
};