# -*- coding: utf-8 -*-

# Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1244

N = int(input())
listinha = []
for i in range(N):
    listinha.append(str(input()))

for i in range(N):
    splitString = listinha[i].split()

    splitString = sorted(splitString, key=len, reverse=True)

    listinha[i] = " ".join(splitString)

for elemento in listinha:
    print(elemento)