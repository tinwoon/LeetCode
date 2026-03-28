class Solution {
public:
    std::vector< std::vector<int> > ret;
    
    int dis(std::vector<int>& t){
        return (pow(t[0],2) + pow(t[1],2));
    }

    std::vector< std::vector<int> > conver_s_v(std::priority_queue< std::pair< int, std::vector<int> > > pq){
        while(!pq.empty()){
            ret.emplace_back(pq.top().second);
            pq.pop();
        }

        return ret;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue< std::pair< int, std::vector<int> > > pq;

        for(int i=0; i < points.size(); i++){
            if(pq.size() < k){
                pq.emplace(std::make_pair(dis(points[i]),points[i]));
            }else{ 
                if((pq.top().first) >dis(points[i])){
                    pq.pop();
                    pq.emplace(std::make_pair(dis(points[i]), points[i]));
                }
            }
        }

        return conver_s_v(pq);
    }
};