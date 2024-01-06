# include <bits/stdc++.h>
using namespace std;

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1804

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N;
    cin >> N;
    vector<int> a (N);
    int len = ceil(sqrt(N));
    vector<int> b (len);


    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
        b[i / len] += a[i];
    }


    char modo;
    int query;


    while (cin >> modo >> query)
    {
        int soma = 0;
        int imprimir = 0;

    
        if (modo == 'a')
        {
            int aux = (query - 1) / len;

            b[aux] = b[aux] - a[query-1];
            a[query-1] = 0;
        }
        else if (modo == '?')
        {
            
            imprimir = 1;
            
            
            for(int i = 0; i <= query-2; ) {
                
                if ((i % len == 0) && (i + len - 1 <= query-2)) {

                    soma += b[i / len];
                    i += len;
                }
                else {

                    soma += a[i];
                    i++;
                }
            }
        }
        if (imprimir) cout << soma << endl;
    }
    

    return 0;
}
