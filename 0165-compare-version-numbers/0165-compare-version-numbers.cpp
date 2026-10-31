class Solution {
public:
    int version_info(std::string& version, int start_index, int end_index){
        int ret = 0;

        for(int k=start_index; k != end_index; k++){
            ret = (ret * 10) + (version[k] - '0');    
        }

        return ret;
    }

    int compareVersion(string version1, string version2) {
        int ver1_st_i = 0, ver2_st_i = 0;

        while((ver1_st_i < version1.size()) || (ver2_st_i < version2.size())){
            int s_v1 = ver1_st_i, s_v2 = ver2_st_i;
            int v1 = 0, v2 = 0;

            for(;ver1_st_i <= version1.size(); ver1_st_i++){
                if(ver1_st_i != version1.size() && version1[ver1_st_i] != '.') continue;

                v1 = version_info(version1, s_v1, ver1_st_i++);
                break;
            }
            for(;ver2_st_i <= version2.size(); ver2_st_i++){
                if(ver2_st_i != version2.size() && version2[ver2_st_i] != '.') continue;

                v2 = version_info(version2, s_v2, ver2_st_i++);
                break;
            }

            if(v1 != v2){
                return v1 < v2 ? -1 : 1;
            }
        }

        return 0;
    }
};