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

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int array[1000];
int found_by_thread = 0;
int thread_number_position = 0;
int target_number = 13; // número que os processos devem buscar
int range_array = 1000; // gera números aleatórios entre 0 e este número

void *thread_function(void *arg) {
    int numThread = *(int *) arg;
    int start = numThread * 200;
    int finish = start + 199;
    printf("filho %d - start[%d] - finish[%d]\n", numThread+1, start, finish);

    for (int i = start; i < finish; i++) {
        if (array[i] == target_number) {
            printf("Thread %d encontrou o número na posicao %d\n", numThread+1, i);
            found_by_thread = numThread+1;
            thread_number_position = i;

            break;
        }
    }

    return NULL;
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("array[%d]::%d\n", i, array[i]);
  }
  printf("\n");
}

int main() {
    // Inicializar o array com valores aleatórios.
    srand(time(NULL));   // Initialization, should only be called once.

    // Returns a pseudo-random integer between 0 and RAND_MAX.
    // random int between 0 and 19
    // int r = rand() % 20;
    int contains = 0;

    for (int i = 0; i < 1000;){
        // int r = rand() % 20;
        // array[i] = r;
        // printf("array[%d]::%d\n", i, array[i]);
        
        // primeira inserção
        if (i == 0){
        array[i] = rand() % range_array;
        i++;
        } else{
            int r = rand() % range_array;
            // checar comparação dos elementos
            for (int j = 0; j < i; j++){
                if (r == array[j]){
                    contains = 1;
                }
            }
            // checar se comparação de elementos tem algum repetido ou não
            if (contains == 0){
                array[i] = r;
                i++;
            } else{
                contains = 0;
            }
        }
    }

    int size = sizeof(array) / sizeof(array[0]);

    printArray(array, size);

    // Criar as threads.
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        printf("THREAD [%d]\n", i + 1);
        if (pthread_create(&threads[i], NULL, thread_function, &i)) {
            perror("Erro ao criar thread");
            exit(1);
        }
        pthread_join (threads[i] ,NULL);
    }

    if (found_by_thread) {
        printf("O número [%d] foi encontrado pela thread [%d] na posicao [%d]\n", target_number, found_by_thread, thread_number_position);
    } else {
        printf("O número não foi encontrado\n");
    }

    return 0;
}
