#include <graphics.h>
#include <time.h>
#include <string.h>

int main() {
    initwindow (200, 200);

    time_t horaAtual = time(0);
    struct tm *hora = localtime(&horaAtual);
    int min = hora->tm_min;
    int contador = 0;

    while (true) {  // Loop infinito para atualizar a hora continuamente

        // Obtenha a hora atual
        time_t agora = time(0);
        struct tm *tempo = localtime(&agora);

        // Converta o tempo para uma string formatada
        char hora_str[8];
        sprintf(hora_str, "%02d:%02d:%02d", tempo->tm_hour, tempo->tm_min, tempo->tm_sec);


        char amPm[10] = "";
        if (tempo->tm_hour > 12) {
            strcpy(amPm, "PM");
        } else {
            strcpy(amPm, "AM");
        }

        outtextxy(110, 100, amPm);
        outtextxy(50, 100, hora_str);
        contador++;

        if(contador > 60){ // Encerra o programa após o contador passar de 60
            return 0;
        }

        delay(1000);  // Espere 1 segundo antes de atualizar novamente
    }

}
