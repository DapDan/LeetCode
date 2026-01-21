/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
        int i, carry, soma;

    i = digitsSize - 1;
    carry = 1;
    while(i >= 0 && carry == 1) {
        soma = digits[i] + carry;
        digits[i] = soma % 10;
        carry = soma / 10;
        i--;
    }

    if(carry == 1) {
        int* result = malloc((digitsSize + 1) * sizeof(int));

        result[0] = 1;
        for (int i = 0; i < digitsSize; i++) {
            result[i + 1] = digits[i];
        }

        *returnSize = digitsSize + 1;
        return result;
    }

    *returnSize = digitsSize;
    return digits;
}