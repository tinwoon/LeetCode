#define MAX(a, b) ((a > b) ? a : b)

int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    int ret = 0;
    int* character = (int*)calloc(128, sizeof(int));
    for(int i=0; i< len; i++){
        memset(character, 0, 128 * sizeof(int));
        int size = 0;
        for(int j=i; j<len; j++){
            if(character[s[j]]) break;
            character[s[j]] = 1;
            size++;
            ret = MAX(ret, size);
        }
    }
    return ret;
}