/*
Tendo um array de 1000 posições, faça um programa que crie 5 threads e:
- Dado um número, procurar esse número no array.
- Cada processo filho, procura 200 posições.
- O thread que encontrar o número, deve imprimir a posição o array onde
se encontra. Também deve "retornar" como valor de saída o número do thread (1,2,3,4,5).
- Os threads que não encontrarem o número devem "retornar" como valor de 
saída o valor 0.
- A função main tem de esperar que todos os threads terminem e imprimir 
o número do thread onde esse número foi encontrado (1,2,3,4,5).

Nota: O array não tem números repetidos.
*/