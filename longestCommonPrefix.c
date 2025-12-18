char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return "";

    int i, j;
    int len = strlen(strs[0]);

    char *res = (char *)malloc(len + 1);

    for (i = 0; i < len; i++) {
        char c = strs[0][i];

        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                res[i] = '\0';
                return res;
            }
        }

        res[i] = c;
    }

    res[len] = '\0';
    return res;
}