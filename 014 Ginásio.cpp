#include <bits/stdc++.h>
using namespace std;

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/2538

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int IP;
    int M;
    int PC;
    int NA;
    int i; 
    int contador;
    int intervaloMax;
    int intervaloMin;
    

    while (cin >> IP >> M) {
        

        FenwickTree test_tree(100001);
        contador = 0;
        

        for (i = 0; i < M; i++) {
            

            cin >> PC >> NA;
            
 
            intervaloMax = PC + IP;
            intervaloMin = PC - IP;
            if (intervaloMax > 100000) intervaloMax = 100000;
            if (intervaloMin <= 0) intervaloMin = 1;
            
            
            if (test_tree.sum(intervaloMin, intervaloMax) <= NA) {
                test_tree.add(PC, 1);
                contador++;
            }
        }

        cout << contador << endl;
    }

    return 0;
}