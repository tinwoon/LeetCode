int strStr(char * haystack, char * needle){
    char* str = strstr(haystack, needle);
    return str != NULL ? str - haystack : -1;
}