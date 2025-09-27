class Solution {
public:
    std::map< std::string, int > case_sensitive_m, upper_lower_m, vowels_error_m;

    std::string convert_vowels(std::string str){
        char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

        for(int i=0; i < str.size(); i++){
            for(int j = 0; j < 5; j++){
                if(str[i] == vowels[j]){
                    str[i] = '_';
                    break;
                }
            }
        }

        return str;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        std::vector< std::string > ans;

        for(int k=0; k < wordlist.size(); k++){
            std::string word = wordlist[k];

            case_sensitive_m[word] = k;

            std::ranges::transform(word, word.begin(),
                           [](unsigned char c){ return std::tolower(c); });

            if(!upper_lower_m.count(word)){
                upper_lower_m[word] = k;
            }

            std::string vowels_sbst = convert_vowels(word);

            if(!vowels_error_m.count(vowels_sbst)){
                vowels_error_m[vowels_sbst] = k;
            }

        }

        for(int k=0; k < queries.size(); k++){
            std::string query = queries[k];

            if(case_sensitive_m.count(query)){
                ans.emplace_back(wordlist[case_sensitive_m[query]]);
            }else{
                std::ranges::transform(query, query.begin(),
                           [](unsigned char c){ return std::tolower(c); });

                if(upper_lower_m.count(query)){
                    ans.emplace_back(wordlist[upper_lower_m[query]]);
                }else{
                    query = convert_vowels(query);

                    if(vowels_error_m.count(query)){
                        ans.emplace_back(wordlist[vowels_error_m[query]]);
                    }else{
                        ans.emplace_back("");
                    }
                }
            }
             
        }

        return ans;
    }
};