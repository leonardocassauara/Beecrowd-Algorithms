# include <bits/stdc++.h>
using namespace std;

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/3428

int main() {

    int numBaloes, i, balao, dardosLancados=0;

    vector<int> dardosVoando (1000001, 0);
    
    cin >> numBaloes;

    for (i = 0; i < numBaloes; i++)
    {
        cin >> balao;

        if (dardosVoando[balao] > 0) 
        {
            dardosVoando[balao]--;
        }
        else
        {
            dardosLancados++;
        }

        dardosVoando[balao-1]++;
    }

    cout << dardosLancados << endl;

    return 0;
}
