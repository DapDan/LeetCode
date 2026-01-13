int removeEspacoFim(char *s) {
    int i, conta;

    conta = 0;
    for(i = strlen(s) - 1; i >= 0; i--) {
        if(s[i] == ' ')
            conta++;
        else
            break;
    }

    return conta;
}

int lengthOfLastWord(char* s) {
    int i, tam, cont, contaEspaco;

    contaEspaco = removeEspacoFim(s);
    tam = strlen(s);
    cont = 0;
    for(i = tam - contaEspaco - 1; i >= 0; i--) {
        if(isspace(s[i]))
            break;

        cont++;
    }

    return cont;
}