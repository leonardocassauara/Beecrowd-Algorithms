# include <bits/stdc++.h>
using namespace std;

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1861

int main() {

    string strAssassino, strAssassinado;
    map<string, pair<bool, int>> pessoas;

    while (cin >> strAssassino >> strAssassinado)
    { 

        pessoas[strAssassino].second = pessoas[strAssassino].second + 1;
        pessoas[strAssassinado].first = 1;                      
    }

    auto it = pessoas.begin();

    cout << "HALL OF MURDERERS" << endl;

    for (; it != pessoas.end(); it++)
    {

        if (it->second.first == 0)
        {

            cout << it->first << " " << it->second.second << endl;
        }
    }

    return 0;
}
