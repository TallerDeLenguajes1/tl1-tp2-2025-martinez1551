// tp2_1_2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main() {
    int i;
    double vt[N];

    srand(time(NULL));  // Inicializar generador aleatorio

    for(i = 0; i < N; i++) {
        *(vt + i) = 1 + rand() % 100;
        printf("%f ", *(vt + i));
    }

    printf("\n");

    return 0;
}
