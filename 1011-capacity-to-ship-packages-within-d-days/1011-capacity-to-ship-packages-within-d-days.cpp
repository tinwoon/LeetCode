class Solution {
public:
    int ans = INT_MAX;

    bool calculate(const int ship_w, const int days, vector<int>& weights){
        int day_count = days;
        int index = 0;

        while(day_count--){
            int rest_weight = ship_w;

            while(index < weights.size() && rest_weight >= weights[index]){
                rest_weight -= weights[index++];

                if(index == weights.size()){
                    ans = std::min(ans, ship_w);

                    return true;
                }
            }

        }

        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int minimum = *std::max_element(weights.begin(), weights.end());
        int maximum = 25000000;
        int s = minimum;
        int e = maximum;

        while( ((s + e) / 2) >= minimum && ((s + e) / 2) <= maximum && s <= e){
            int mid = (s + e)/2;
            
            if(calculate(mid, days, weights)){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }

        return ans;
    }
};