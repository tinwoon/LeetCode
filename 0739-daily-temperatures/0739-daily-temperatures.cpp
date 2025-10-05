class Solution {
public:
    //temperature, idx
    std::stack< std::pair<int, int> > s;
    std::vector<int> ans;

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ans.assign(temperatures.size(), 0);

        for(int node = 0; node < temperatures.size(); node++){
            while(!s.empty() && s.top().first < temperatures[node]){
                ans[s.top().second] = node - s.top().second;
                s.pop();
            }

            s.push(std::make_pair(temperatures[node], node));
        }

        return ans;
    }
};