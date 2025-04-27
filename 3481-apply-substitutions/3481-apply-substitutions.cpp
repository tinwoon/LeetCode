class Solution {
public:
    void conversing_replacements(std::vector< std::vector<string> >& replacements, std::map<char, std::string>& replace_map){
        for(int k=0; k < replacements.size(); k++){
            replace_map[replacements[k][0][0]] = replacements[k][1];
        }
    }

    std::string converting(std::string& text, std::map<char, std::string>& replace_map){
        std::string ret = "";
        bool find_f = false;

        for(int k=0; k < text.size(); k++){
            if(text[k] == '%'){
                ret += converting(replace_map[text[k+1]], replace_map);
                find_f = !!(k += 2);
            }
            else ret += text[k];
        }

        return ret;
    }

    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        bool open_sub = false;
        std::string ret = "";
        std::map<char, std::string> replace_map;

        conversing_replacements(replacements, replace_map);

        ret += converting(text, replace_map);

        return ret;
    }
};