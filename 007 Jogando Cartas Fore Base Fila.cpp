# include <bits/stdc++.h>
using namespace std;

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1110

void atualizaFilaDeCartas(queue<int> &filaCartas, int numCartas, queue<int> &cartasFora) {

    int i, aux;

    while (1) 
    {
        aux = filaCartas.front();
        cartasFora.push(aux);
        filaCartas.pop();
        aux = filaCartas.front();
        filaCartas.pop();
        filaCartas.push(aux);

        if (filaCartas.size() < 2) break;
    }
}


void limparEstruturas(queue<int> &filaCartas, queue<int> &cartasFora) {

    while (! filaCartas.empty()) filaCartas.pop();
    while (! cartasFora.empty()) cartasFora.pop();
}


int main() {

    int numCartas, i;
    
    queue<int> filaCartas;
    queue<int> cartasFora;

    cin >> numCartas;

    while (numCartas != 0) {

        for (i = 1; i <= numCartas; i++) 
        {
            filaCartas.push(i);
        }

        atualizaFilaDeCartas(filaCartas, numCartas, cartasFora);

        printf("Discarded cards: ");
        for (i = 0; i < numCartas; i++) 
        {
            if (i <= numCartas - 3) 
            {
                printf("%d, ", cartasFora.front());
                cartasFora.pop();
            }
            else if (i <= numCartas - 2) printf("%d\n", cartasFora.front());
            else printf("Remaining card: %d\n", filaCartas.front()); 
        }

        cin >> numCartas;

        limparEstruturas(filaCartas, cartasFora);
    }

}