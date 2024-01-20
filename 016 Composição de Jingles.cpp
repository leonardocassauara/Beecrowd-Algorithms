# include <bits/stdc++.h>
using namespace std;

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1430

int main() {

    int i;
    string entrada;

    cin >> entrada;

    map<char, int> notas;
    notas['W'] = 64;
    notas['H'] = 32;
    notas['Q'] = 16;
    notas['E'] = 8;
    notas['S'] = 4;
    notas['T'] = 2;
    notas['X'] = 1;

    while (entrada != "*") {

        int tempo = 0, contador = 0;

        for (i = 0; i < entrada.length(); i++) {
            
            if (entrada[i] == '/') {
                
                if (tempo == 64) contador++;
                
                tempo = 0;
            }
            else if(entrada[i] == 'W') tempo = tempo + notas['W'];
            else if (entrada[i] == 'H') tempo = tempo + notas['H'];
            else if (entrada[i] == 'Q') tempo = tempo + notas['Q'];
            else if (entrada[i] == 'E') tempo = tempo + notas['E'];
            else if (entrada[i] == 'S') tempo = tempo + notas['S'];
            else if (entrada[i] == 'T') tempo = tempo + notas['T'];
            else if (entrada[i] == 'X') tempo = tempo + notas['X'];
        }
        cout << contador << endl;
        cin >> entrada;
    }

    return 0;
}