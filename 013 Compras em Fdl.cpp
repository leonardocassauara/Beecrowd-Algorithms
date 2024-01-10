#include <bits/stdc++.h>
using namespace std;
# define endl "\n"

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/2531

int n=100005;
vector<pair<int, int>> t (300001);


void build(vector<pair<int, int>> &a, int v, int tl, int tr) {
    if (tl == tr) {

        t[v].first = a[tl].first;
        t[v].second = a[tl].second;
    }
    else {

        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v].first = min(t[v*2].first, t[v*2+1].first);
        t[v].second = max(t[v*2].second, t[v*2+1].second);
    }
}


void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v].first = new_val;
        t[v].second = new_val;
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v*2, tl, tm, pos, new_val);
        }

        else {
            update(v*2+1, tm+1, tr, pos, new_val);
        }
        t[v].first = min(t[v*2].first, t[v*2+1].first);
        t[v].second = max(t[v*2].second, t[v*2+1].second);
    }
}


pair<int, int> sub(int v, int tl, int tr, int l, int r) {

    if (l > r) {
        return {100001, -1}; 
    }

    if ((l == tl) && (r == tr)) {
        return t[v];
    }

    int tm = (tl + tr) / 2;
    pair<int, int> esquerda = sub(v*2, tl, tm, l, min(r, tm));
    pair<int, int> direita = sub(v*2+1, tm+1, tr, max(l, tm+1), r);

    return {min(esquerda.first, direita.first), max(esquerda.second, direita.second)};
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int i;
    int numLojas;
    int numQueries;
    int aux;
    int queryMode;
    int queryPosStart;
    int queryValEnd;
    pair<int, int> queryResult;

    while (cin >> numLojas) {

        vector<pair<int, int>> lojas (numLojas);


        for (i = 0; i < numLojas; i++) {
            cin >> aux;
            lojas[i].first = aux;
            lojas[i].second = aux;
        }


        build(lojas, 1, 0, numLojas-1);


        cin >> numQueries;

        for (i = 0; i < numQueries; i++) {

            cin >> queryMode >> queryPosStart >> queryValEnd;



            if (queryMode == 1) {

                update(1, 0, numLojas-1, queryPosStart-1, queryValEnd);
            }

            else if (queryMode == 2) {

                queryResult = sub(1, 0, numLojas-1, queryPosStart-1, queryValEnd-1);
                aux = queryResult.second - queryResult.first;
                cout << aux << endl;
            }
        }
    }

    return 0;
}