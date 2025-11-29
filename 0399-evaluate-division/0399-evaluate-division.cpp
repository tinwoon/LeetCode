
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        std::map< std::string, std::vector< std::pair< std::string, double > > > m;
        std::vector< double > ans;
        std::set< std::string > variables;

        for(int k=0; k < equations.size(); k++){
            m[equations[k][0]].emplace_back(std::make_pair(equations[k][1], values[k]));
            m[equations[k][1]].emplace_back(std::make_pair(equations[k][0], 1 / values[k]));

            variables.emplace(equations[k][0]);
            variables.emplace(equations[k][1]);
        }

        for(int q_i = 0; q_i < queries.size(); q_i++){
            std::map< std::string, bool > visited;
            std::queue< std::pair< std::string, double > > q;
            std::string numerator = queries[q_i][0];
            std::string denominator = queries[q_i][1];
            double output = -1;

            if(!std::count(variables.begin(), variables.end(), numerator) || !std::count(variables.begin(), variables.end(), denominator)){
                ans.emplace_back(output);
                continue;
            }

            q.emplace( std::make_pair(numerator, 1));

            while(!q.empty()){
                auto numerator_info = q.front();
                q.pop();

                numerator = numerator_info.first;
                double multiv = numerator_info.second;

                if(numerator == denominator){
                    output = multiv;
                    break;
                }

                for(int k=0; k < m[numerator].size(); k++){
                    if(!visited[m[numerator][k].first]){
                        q.emplace(std::make_pair(m[numerator][k].first, multiv * m[numerator][k].second));
                        visited[m[numerator][k].first] = true;
                    }
                }
            }

            ans.emplace_back(output);
        }

        return ans;
    }
};