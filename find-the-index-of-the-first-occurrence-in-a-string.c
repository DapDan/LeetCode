int strStr(char* haystack, char* needle) {
    char *pos;

    if(*needle == '\0')
        return 0;
    
    pos = strstr(haystack, needle);
    if(pos != NULL)
        return pos - haystack;
    else
        return -1;
}