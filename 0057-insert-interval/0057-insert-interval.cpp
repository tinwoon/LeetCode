class Solution {
public:
    
    void calculate(vector<vector<int>>& intervals, vector<int>& newInterval){
        if(intervals.size() == 0){
            intervals.emplace_back(newInterval);
            return;
        }
        
        int a,b,c,d,k;
        bool push_f = false;
        c = newInterval[0];
        d = newInterval[1];
        
        for(k = 0; k < intervals.size(); k++){
            a = intervals[k][0];
            b = intervals[k][1];
            
            if((d < a) || (b < c)){
                continue;
            }else if((c < a) && (a <= d) && (d <= b)){
                intervals[k][0] = c;
                intervals[k][1] = b;
                push_f = true;
                break;
            }else if((a <= c) && (c <= d) && (d <= b)){
                intervals[k][0] = a;
                intervals[k][1] = b;
                push_f = true;
                break;
            }else if((c < a) && (a <= b) && (b < d)){
                intervals[k][0] = c;
                intervals[k][1] = d;
                push_f = true;
                break;
            }else if((a <= c) && (c <= b) && (b < d)){
                intervals[k][0] = a;
                intervals[k][1] = d;
                push_f = true;
                break;
            }
        }
        
        if(!push_f){
            intervals.emplace_back(newInterval);
            std::sort(intervals.begin(), intervals.end());
        }
        
        while(k + 1 < intervals.size()){
            a = intervals[k][0];
            b = intervals[k][1];
            c = intervals[k + 1][0];
            d = intervals[k + 1][1];
            
            if((d < a) || (b < c)){
                k++;
                continue;
            }else if((c < a) && (a <= d) && (d <= b)){
                intervals[k][0] = c;
                intervals[k][1] = b;
                intervals.erase(intervals.begin() + (k + 1));
            }else if((a <= c) && (c <= d) && (d <= b)){
                intervals[k][0] = a;
                intervals[k][1] = b;
                intervals.erase(intervals.begin() + (k + 1));
            }else if((c < a) && (a <= b) && (b < d)){
                intervals[k][0] = c;
                intervals[k][1] = d;
                intervals.erase(intervals.begin() + (k + 1));
            }else if((a <= c) && (c <= b) && (b < d)){
                intervals[k][0] = a;
                intervals[k][1] = d;
                intervals.erase(intervals.begin() + (k + 1));
            }
        }
        
        return;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        calculate(intervals, newInterval);
        return intervals;
    }
};