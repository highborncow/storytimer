//Augusto Avelino do Prado Dell'Agnolo
#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED

COORD coord = {0, 0};

static const int black = 0;
static const int blue = 1;
static const int green = 2;
static const int cyan = 3;
static const int red = 4;
static const int magenta = 5;
static const int brown = 6;
static const int lightgray = 7;
static const int darkgray = 8;
static const int lightblue = 9;
static const int lightgreen = 10;
static const int lightcyan = 11;
static const int lightred = 12;
static const int lightmagenta = 13;
static const int yellow = 14;
static const int white = 15;

void gotoxy(int x, int y){ //Código do professor
   coord.X = x;
   coord.Y = y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void setcolor(int ForgC){ //Código do professor
// As cores sao:
// 0 = preto 1 = azul 2 = verde ate 15 = branco
// atributodecor = cordaletra + cordofundo * 16
// para escrever com texto vermelho no fundo amarelo 4 + 14*16 = 228
// vemelho claro no fundo amarelo  12 + 14*16 = 236
// alguns compiladores nao aceitam o fundo

     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
//Redimensiona tela do jogo
void screensize(int x, int y){ //Retirado de: http://cboard.cprogramming.com/windows-programming/55672-maximizing-console-window-full-screen.html
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSBSize = GetLargestConsoleWindowSize(hOut);
    SMALL_RECT DisplayArea = {0, 0, 0, 0};

    SetConsoleScreenBufferSize(hOut, NewSBSize);

    DisplayArea.Right = NewSBSize.X - x;
    DisplayArea.Bottom = NewSBSize.Y - y;

    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
}

void hidecursor() {
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

#endif // TELA_H_INCLUDED
