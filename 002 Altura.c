#include <stdio.h>
#include <stdlib.h>

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1566

void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];
  z = i;
  while (iv <= m && ic <= f) {
    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }
  while (iv <= m) v[z++] = c[iv++];
  while (ic <= f) v[z++] = c[ic++];
}


void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;
  int m = (i + f) / 2;
  sort(v, c, i, m);
  sort(v, c, m + 1, f);
  if (v[m] <= v[m + 1]) return;
  merge(v, c, i, m, f);
}


void mergesort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}


void imprimirVetorOrdenado(int N, int* vetor) {
	int i;
	
	for (i = 0; i < N; i++){
		
		if (i != N - 1) {
			printf("%d ", vetor[i]);
		}
		else {
			printf("%d", vetor[i]);	
		}
		
	}
	printf("\n");
}


void lerPessoas(int N, int* vetor) {
	int i;
	for (i = 0; i < N; i++){
		scanf("%d", &vetor[i]);
	}
}


int main() {
    
    int casosDeTeste;
	int i, numPessoas;
	scanf("%d", &casosDeTeste);
	
	for (i = 0; i < casosDeTeste; i++){
		
		scanf("%d", &numPessoas);
		
		int* pessoas = malloc(numPessoas*sizeof(int));
		lerPessoas(numPessoas, pessoas);
		
		mergesort(pessoas, numPessoas);
		
		imprimirVetorOrdenado(numPessoas, pessoas);
		free(pessoas);
	}

	return 0;
}
