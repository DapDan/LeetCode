int valores(char c) {
    return c - 'A' + 1;
}

int titleToNumber(char* columnTitle) {
    int i, j, tam, res;

    res = 0;
    j = 0;
    tam = strlen(columnTitle);
    for(i = tam - 1; i >= 0; i--) {
        res += valores(columnTitle[i]) * pow(26, j++);
    }

    return res;
}