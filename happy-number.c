#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isHappy(int n) {
    long int potencia, soma, contador;

    contador = 0;
    while(n != 1 && contador < 20) {
        potencia = 1;
        soma = 0;
        while(potencia <= n)
            potencia *= 10;
        potencia /= 10;

        while(potencia > 0) {
            int digito = n / potencia;
            //printf("%d ", digito);
            soma += pow(digito, 2);
            n %= potencia;
            potencia /= 10;
        }

        //printf("\n%d", soma);
        n = soma;
        contador++;
    }

    if(n == 1)
        return true;
    return false;
}