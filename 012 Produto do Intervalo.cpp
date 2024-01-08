# include <bits/stdc++.h>
using namespace std;

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1301

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int tamanhoVetor;
    int numQueries;
    int i;
    int aux;
    int k;
    int j;


    while(cin >> tamanhoVetor >> numQueries) {


        int sqrtTamanhoVetor = ceil(sqrt(tamanhoVetor));
        vector<int> vetorBase (tamanhoVetor, 1);
        vector<int> vetorSqrt (sqrtTamanhoVetor, 1);


        for (i = 0; i < tamanhoVetor; i++) {

            cin >> aux;

            if (aux > 0) aux = 1;
            else if (aux < 0) aux = -1;

            vetorBase[i] = aux;
            vetorSqrt[i / sqrtTamanhoVetor] *= aux;
        }


        char modo;
        int qIni;
        int qFimVal;
        string resposta = "";

        for(i = 0; i < numQueries; i++) {

            int produto = 1;
            cin >> modo >> qIni >> qFimVal;
            
            qIni--;

            if (modo == 'C') {
                
                if (qFimVal > 0) qFimVal = 1;
                else if (qFimVal < 0) qFimVal = -1;
                
                
                if (vetorBase[qIni] != 0) {
                    
                    aux = (qIni) / sqrtTamanhoVetor;
                    vetorSqrt[aux] /= vetorBase[qIni];
                    vetorBase[qIni] = qFimVal;
                    vetorSqrt[aux] *= vetorBase[qIni];
                }
                else {
                    
                    int novoValor = 1;
                    aux = qIni - (qIni % sqrtTamanhoVetor);
                    vetorBase[qIni] = qFimVal;
                    for (j = aux; j <= aux + sqrtTamanhoVetor - 1; j++) {
                        novoValor *= vetorBase[j];
                    }
                    vetorSqrt[qIni / sqrtTamanhoVetor] = novoValor;
                }
            }
            else if (modo == 'P') {
                
                qFimVal--;
                
                for(k = qIni; k <= qFimVal;) {
                    
                    if ((k % sqrtTamanhoVetor == 0) && (k + sqrtTamanhoVetor - 1 <= qFimVal)) {

                        produto *= vetorSqrt[k / sqrtTamanhoVetor];
                        k += (sqrtTamanhoVetor);
                    }
                    else {

                        produto *= vetorBase[k];
                        k++;
                    }
                }

                if (produto > 0) resposta += (string)"+";
                else if (produto < 0) resposta += (string)"-";
                else resposta += (string)"0";
            }
        }

        cout << resposta << endl;
        resposta = "";
    }
    

    return 0;
}
