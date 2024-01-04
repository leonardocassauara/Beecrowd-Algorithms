# include <bits/stdc++.h>
using namespace std;

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/3427

int main() {

    int xInicialAlvo, xEntradaOrigem, contador=0, N;

    cin >> N; 
    cin >> xEntradaOrigem;

    xInicialAlvo = 1 << (N-1);

    while (xInicialAlvo != xEntradaOrigem)
    {

        contador++; // O(1)

        xEntradaOrigem = xEntradaOrigem & ~xInicialAlvo;

        xEntradaOrigem = xEntradaOrigem << 1;
    }

    cout << contador << endl;

    return 0;
}
