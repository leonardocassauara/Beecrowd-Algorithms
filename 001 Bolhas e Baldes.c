# include <stdio.h>
# include <stdlib.h>

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1088

void lerSequencia (int N, int* sequencia) {

    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &sequencia[i]);
    }
}


int* lerQuestao (int* N) {

    scanf("%d", N);
        if (*N == 0) {

            exit(0);
        }
    
    int* sequencia = malloc((*N)*sizeof(int));
    lerSequencia(*N, sequencia);

    return sequencia;
}


void imprimirDados (int N, int* sequencia, int turnos) {

    int i;
    printf("\n");
    for (i = 0; i < N; i++) {

        printf("%d", sequencia[i]);
    }
    printf("\nN: %d turnos: %d", N, turnos);
}


void calcularTurnos(int* turnos, int N, int* sequencia) {

    int i = 0, aux, aux1;
    while(i < N) {

        if (sequencia[i] != i+1) {

            aux = sequencia[i];

            sequencia[i] = sequencia[sequencia[i]];

            sequencia[aux] = aux;

            *turnos = *turnos + 1;
        }
        else {

            i++;
        }
    }
}


int main() {

    int N, turnos=0;
    int* sequencia;

    while (1) {

        sequencia = lerQuestao(&N);

        calcularTurnos(&turnos, N, sequencia);

        imprimirDados(N, sequencia, turnos);
        printf(turnos % 2 == 0 ? "Carlos" : "Marcelo");
        turnos = 0;
        free(sequencia);
    }

    return 0;
}