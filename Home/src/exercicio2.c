/*
Tendo um array de 1000 posições, faça um programa que crie 5 processos e:
- Dado um número, procurar esse número no array.
- Cada processo filho, procura 200 posições.
- O processo que encontrar o número, deve imprimir a posição o array onde
se encontra. Também deve "retornar" como valor de saída o número do processo(1,2,3,4,5).
- Os processos que não encontrarem o número devem "retornar" como valor de 
saída o valor 0.
- O processo pai tem de esperar que todos os filhos terminem e imprimir 
o número do processo onde esse número foi encontrado (1,2,3,4,5).

Nota: O array não tem números repetidos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("vetor[%d]::%d\n", i, array[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]){
    int vetor[1000];
    srand(time(NULL));   // Initialization, should only be called once.

    // Returns a pseudo-random integer between 0 and RAND_MAX.
    // random int between 0 and 19
    // int r = rand() % 20;
    int contains = 0;
    int totalIteracoes = 0;

    for (int i = 0; i < 1000;){
        totalIteracoes++;
        // int r = rand() % 20;
        // vetor[i] = r;
        // printf("vetor[%d]::%d\n", i, vetor[i]);
        
        // primeira inserção
        if (i == 0){
        vetor[i] = rand() % 1000;
        i++;
        } else{
            int r = rand() % 1000;
            // checar comparação dos elementos
            for (int j = 0; j < i; j++){
                if (r == vetor[j]){
                    contains = 1;
                }
            }
            // checar se comparação de elementos tem algum repetido ou não
            if (contains == 0){
                vetor[i] = r;
                i++;
            } else{
                contains = 0;
            }
        }
    }

    int size = sizeof(vetor) / sizeof(vetor[0]);

    printArray(vetor, size);
    printf("Size array::%d\n", size);

}