#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>


#include "tela.h"

#define X 4
#define Y 1

typedef struct time {
    int seconds;
    int minutes;
    int hours;
} t;

int main() {
    t tempo;
    int ptimes = 0;
    int penalty = 5;
    int aux;
    int over = 0;
    char tc = '0';
    gotoxy(X + 1, Y);
    setcolor(lightgreen);
    printf("Time: ");
    scanf("%d:%d:%d", &tempo.hours, &tempo.minutes, &tempo.seconds);
    hidecursor();
    while (over == 0) {
        Sleep(1000);
        if (kbhit()) {
            tc = getch();
        }
        if (tc == ' ') {
            ptimes++;
            penalty += 5;
            aux = penalty;
            while (aux >= 3600) {
                aux -= 3600;
                tempo.hours++;
            }
            while (aux >= 60) {
                aux -= 60;
                tempo.minutes++;
            }
            tempo.seconds += aux;
            gotoxy(X - 2, Y + 3);
            setcolor(lightmagenta);
            printf("Penalty: %d seconds", penalty);
            tc = '0';
        }
        while (tempo.seconds >= 60) {
            tempo.seconds -= 60;
            tempo.minutes++;
        }
        while (tempo.minutes >= 60) {
            tempo.minutes -= 60;
            tempo.hours++;
        }

        if (tempo.seconds > 0) {
                tempo.seconds--;
        }
        else {
            if (tempo.minutes > 0) {
                tempo.seconds = 59;
                tempo.minutes--;
            }
            else {
                if (tempo.hours > 0) {
                    tempo.seconds = 59;
                    tempo.minutes = 59;
                    tempo.hours--;
                }
            }
        }

        gotoxy(X + 4, Y + 2);
        setcolor(yellow);
        printf("%02d:%02d:%02d", tempo.hours, tempo.minutes, tempo.seconds);

        if (tempo.hours == 0 && tempo.minutes == 0 && tempo.seconds == 0) {
            over = 1;
        }
    }
    printf("\a");
    setcolor(lightred);
    gotoxy(X + 2, Y + 5);
    printf("TIME'S UP!!!");
    setcolor(lightblue);
    gotoxy(X - 1, Y + 6);
    printf("What have we got!?");
    setcolor(lightgray);
    tc = getch();
    gotoxy(0, Y + 8);
}
