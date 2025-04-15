#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_PC 5

struct compu {
    int velocidad;         // GHz (1 - 3)
    int anio;              // Anio (2015 - 2024)
    int cantidad_nucleos;  // Nucleos (1 - 8)
    char *tipo_cpu;        // Tipo de procesador
};

// Funciones
void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);

int main() {
    struct compu pcs[CANT_PC];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    srand(time(NULL)); // semilla para rand

    for (int i = 0; i < CANT_PC; i++) {
        pcs[i].velocidad = 1 + rand() % 3 ;
        pcs[i].anio = 2015 + rand() % 10;
        pcs[i].cantidad_nucleos = 1 + rand() % 8;
        pcs[i].tipo_cpu = tipos[rand() % 6];
    }

    listarPCs(pcs, CANT_PC);
    printf("\n--- PC mas vieja ---\n");
    mostrarMasVieja(pcs, CANT_PC);
    printf("\n--- PC mas veloz ---\n");
    mostrarMasVeloz(pcs, CANT_PC);

    return 0;
}

void listarPCs(struct compu pcs[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("PC %d:\n", i + 1);
        printf("  Velocidad: %d GHz\n", pcs[i].velocidad);
        printf("  Anio: %d\n", pcs[i].anio);
        printf("  Nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("  Tipo CPU: %s\n", pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad) {
    int aux = 0;
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].anio < pcs[aux].anio) {
            aux = i;
        }
    }
    printf("Anio: %d | Velocidad: %d GHz | Nucleos: %d | CPU: %s\n",
           pcs[aux].anio, pcs[aux].velocidad, pcs[aux].cantidad_nucleos, pcs[aux].tipo_cpu);
}

void mostrarMasVeloz(struct compu pcs[], int cantidad) {
    int aux = 0;
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].velocidad > pcs[aux].velocidad) {
            aux = i;
        }
    }
    printf("Velocidad: %d GHz | Anio: %d | Nucleos: %d | CPU: %s\n",
           pcs[aux].velocidad, pcs[aux].anio, pcs[aux].cantidad_nucleos, pcs[aux].tipo_cpu);
}
