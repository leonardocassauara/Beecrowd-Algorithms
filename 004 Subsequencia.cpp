# include <bits/stdc++.h>
using namespace std;

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1507

int verificarSubstring (char casoTeste[], char possivelSub[], int tamanhoCasoTeste, int tamanhoPossivelSub) {
    
    int i, j=0;
    
    for (i = 0; i < tamanhoCasoTeste; i++) {

        if (casoTeste[i] == possivelSub[j]) {

            j++;
        }
    }
    
    if (j == tamanhoPossivelSub) {
        return 1;
    }
    return 0;
}


int main() {
    int N, i, j;
    char casoTeste[100000];
    
    scanf("%d", &N);

    int turno, contador=0;
    vector<int> p;
    
    for (i = 0; i < N; i++) {
        
        int M;
        scanf("%s%d", casoTeste, &M);
        
        for (j = 0; j < M; j++) {
            
            char possivelSub[101];
            scanf("%s", possivelSub);

            int tamanhoCasoTeste = strlen(casoTeste);
            int tamanhoPossivelSub = strlen(possivelSub);
            
            turno = verificarSubstring(casoTeste, possivelSub, tamanhoCasoTeste, tamanhoPossivelSub);
            contador++;
            p.push_back(turno);
        }  
    }

    for (i = 0; i < contador; i++) {

        if (p[i] == 1) {

            printf("Yes");
        }
        else {

            printf("No");
        }
        printf("\n");
    }

    return 0;
}