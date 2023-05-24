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
#include <unistd.h>
#include <sys/wait.h>
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

    for (int i = 0; i < 1000;){
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

    for(int i = 0; i <= 4; i++){
        pid_t child_pid = fork();
        if(child_pid == 0){
            // printf("\nPAI[%d] - FILHO .Processo filho.PID[%d]: |%d|\n", getppid(), i, getpid());

            //  Define posição inicial e fim para procurar no array.
            int start = i * 200;
            int finish = start + 199;

            printf("filho %d - start[%d] - finish[%d]\n", i +1, start, finish);
            
            for (int j = start; j < finish; j++) {
                if(vetor[j] == 13){ // Procura se o vetor possui o seguinte valor.
                    printf("Filho %d encontrou o número na posição %d\n", i + 1, j);
                    exit(i +1);
                }
            }
            exit(0);
        }

    }


    int status;
    int found_by_child = 0;
    int child_number = 0;

    for (int i = 1; i < 5; i++) {
        wait(&status);

        // WIFEXITED() is true if the process exited normally via a call to exit. 
        // WEXITSTATUS() if WIFEXITED is true, this returns the value passed to exit by the child.
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            // Este filho encontrou o número.
            found_by_child = WEXITSTATUS(status);
            child_number = i +1;
            break;
        }
    }

    if (found_by_child != 0) {
        printf("O número foi encontrado pelo filho [%d]\n", found_by_child);
    } else {
        printf("O número não foi encontrado\n");
    }



}