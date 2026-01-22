char* addBinary(char* a, char* b) {
    int i, j, carry, k, sum, l, r;
    char *res;
    char aux;

    i = strlen(a) - 1;
    j = strlen(b) - 1;
    carry = 0;

    res = malloc(10005);
    k = 0;

    while (i >= 0 || j >= 0 || carry) {
        sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        res[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    res[k] = '\0';

    //inverter a string
    for (l = 0, r = k - 1; l < r; l++, r--) {
        aux = res[l];
        res[l] = res[r];
        res[r] = aux;
    }

    return res;
}