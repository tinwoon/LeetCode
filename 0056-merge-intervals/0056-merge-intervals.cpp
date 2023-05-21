class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {        
        std::sort(intervals.begin(), intervals.end());
        std::stack< std::vector<int> > left, right;
        
        left.emplace(intervals[0]);
        for(int k = intervals.size() - 1; k >= 1; k--){
            right.emplace(intervals[k]);
        }
        
        while(!right.empty()){
            if(left.top()[1] >= right.top()[0]){
                std::vector<int> nsrt = {left.top()[0], std::max(left.top()[1], right.top()[1])};
                left.pop();
                right.pop();
                left.push(nsrt);
            }else{
                left.push(right.top());
                right.pop();
            }
        }
        
        intervals.clear();
        while(!left.empty()){
            intervals.emplace_back(left.top());
            left.pop();
        }
        
        std::reverse(intervals.begin(), intervals.end());
        
        return intervals;
    }
};