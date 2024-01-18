# include <bits/stdc++.h>
using namespace std;

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1310

int A[55];

int subVetorSomaMax(int* V, int N) {
    int resposta = 0;
    A[0] = 0;

    int i, j;

    for (i = 1; i < N; i++) {
        A[i] = A[i-1] + V[i];
    }

    for (i = 1; i < N; i++) {
        
        for (j = i; j < N; j++) {
            resposta = max(resposta, A[j] - A[i-1]);
        }
    }

    return resposta;
}


int main () {

    int N;
    int custoDia;
    int i;
    int resposta;
    int valor;
    
    while (cin >> N) {
        
        cin >> custoDia;
        int vetorBase[N+1];

        for (i = 1; i < N+1; i++) {
            cin >> valor;
            vetorBase[i] = valor - custoDia;
        }
        
        resposta = subVetorSomaMax(vetorBase, N+1);

        cout << resposta << endl;
    }

    return 0;
}