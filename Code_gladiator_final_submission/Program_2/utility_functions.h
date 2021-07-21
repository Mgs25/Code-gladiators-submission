#ifndef _GOTOXY_H_
#define _GOTOXY_H_

// Custom gotoxy function to move cursor
void gotoxy(int a, int b) {
    COORD c;
    c.X = a;
    c.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);    
}

#endif