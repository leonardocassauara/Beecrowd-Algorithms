# include <bits/stdc++.h>
using namespace std;

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/3429

void inserir(string valor, map<string, int> &ocorrencias)
{
    
    map<string, int>::iterator x = ocorrencias.find(valor);
    
    if (x != ocorrencias.end())
    {
        x->second = x->second + 1;
    }
    else 
    {
        ocorrencias[valor] = 1;
    }
}


int main() {

    int N, wordLen, i, highestValue;
    char k;
    string aux, highestKey;

    map<string, int>ocorrencias;
    map<string, int>::iterator it;
    vector<string> words;

    cin >> N;          
    cin >> wordLen;     
    for(i = 0; i < N; i++)
    {
        cin >> aux;
        words.push_back(aux);
    }

    for(i = 0; i < N; i++)
    {

        int iteratorAst = words[i].find("*");
        for (k = 'a'; k <= 'z'; k++)        
        {
            string copia = words[i];
            copia[iteratorAst] = k;
            inserir(copia, ocorrencias);
        }
    }


    highestValue = ocorrencias.begin()->second;
    highestKey = ocorrencias.begin()->first;


    for (it = ocorrencias.begin(); it != ocorrencias.end(); it++)
    {
        
        if (it->second > highestValue)
        {
            highestValue = it->second;
            highestKey = it->first;
        }
    }


    cout << highestKey << " " << highestValue << endl;

    return 0;
}
