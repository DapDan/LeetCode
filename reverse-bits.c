int reverseBits(int n) {
    int i, j, bit;
    char s[101];
    j = 0;
    for(i = 31; i >= 0; i--) {
        bit = (n >> i) & 1;
        //printf("%d", bit);
        s[j++] = bit + '0';
    }

    s[j] = '\0';
    //printf("%s", s);
    for(i = 0; i < 32/2; i++) {
        char aux = s[i];
        s[i] = s[32 - i - 1];
        s[32 - i - 1] =  aux;
    }

    //puts("");
    //printf("%s", s);

    int decimal = 0;
    for(i = 0; i < 32; i++) {
        if(s[i] == '1')
            decimal = (decimal << 1) | 1;
        else if(s[i] == '0')
            decimal = decimal << 1;
    }

    //puts("");
    //printf("%d", decimal);
    
    return decimal;
}
