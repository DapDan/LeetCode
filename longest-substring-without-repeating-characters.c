int lengthOfLongestSubstring(char* s) {
    int vistos[256] = {0};   //ASCII
    int inicio = 0;
    int maximo = 0;

    for (int fim = 0; s[fim] != '\0'; fim++) {
        while (vistos[(unsigned char)s[fim]] == 1) {
            vistos[(unsigned char)s[inicio]] = 0;
            inicio++;
        }
        
        vistos[(unsigned char)s[fim]] = 1;

        int tamanho_atual = fim - inicio + 1;
        if (tamanho_atual > maximo) {
            maximo = tamanho_atual;
        }
    }

    return maximo;
}