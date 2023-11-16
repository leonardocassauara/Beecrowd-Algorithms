# include <stdio.h>
# include <stdlib.h>

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/2422

void lerSequencia (int N, int* sequencia) {

    int i;
    for (i = 0; i < N; i++) {

        scanf("%d", &sequencia[i]);
    }
}


int* lerQuestao (int* N, int* M) {

    scanf("%d", N);
    int* sequencia = malloc((*N)*sizeof(int));
    lerSequencia(*N, sequencia);
    scanf("%d", M);

    return sequencia;
}


void imprimirDados (int N, int M, int* sequencia, int* vetorResposta) {

    int i;

    printf("Sequencia: ");

    for (i = 0; i < N; i++) {
        
        printf("%d ", sequencia[i]);
    }

    printf("\n N: %d M: %d", N, M);
    printf("\nVetor Resposta: %d %d", vetorResposta[0], vetorResposta[1]);
}


int buscaBinaria (int valorProcurado, int tamanhoSeq, int* sequencia) {

    int inicio = 0;
    int fim = tamanhoSeq - 1;
    int meio;

    while (inicio <= fim) {

        meio = (inicio + fim) / 2;
        
        if (sequencia[meio] == valorProcurado) {

            return sequencia[meio];
        }
        if (sequencia[meio] < valorProcurado) {

            inicio = meio + 1;
        }
        else {

            fim = meio - 1;
        }
    }
    
    return 0;
}


void implementarLogicaComBuscaBinaria (int tamanhoSeq, int* sequencia, int M, int* vetorResposta) {

    int x = 0;
    int valorProcurado = M - sequencia[x];
    int valorEncontrado = buscaBinaria(valorProcurado, tamanhoSeq, sequencia);

    while (!valorEncontrado) {

        x++;
        valorProcurado = M - sequencia[x];
        valorEncontrado = buscaBinaria(valorProcurado, tamanhoSeq, sequencia);
    }

    vetorResposta[0] = sequencia[x];
    vetorResposta[1] = valorEncontrado;
}


int main() {

    int N, M;

    int* sequencia = lerQuestao(&N, &M);
    int* vetorResposta = malloc(2*sizeof(int));

    implementarLogicaComBuscaBinaria(N, sequencia, M, vetorResposta);
    printf("%d %d\n", vetorResposta[0], vetorResposta[1]);

    free(vetorResposta);
    free(sequencia);
    return 0;
}
