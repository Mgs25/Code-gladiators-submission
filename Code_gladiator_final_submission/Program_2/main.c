#include <stdio.h> 
#include <conio.h>
#include <time.h>
#include <windows.h>
//User defined headers
#include "utility_functions.h"
#include "emoji_templates.h"
#include "read_emoji.h"
#include "draw.h"
#define TRUE 1

/**************************************************
 * Program to generate robot-like emoji at random
 * points in the output console within the screen
 * bounds.
 * Emoji implemented,
 * -> Happy
 * -> Sad
 * -> Grimace
 * -> Cry
 * -> Angry
 * 
 * Please, maximize the console window before
 * choosing the emoji.
 * Tested on gcc compiler.
 *************************************************/

// Function to loop the drawing until a key is pressed
void loop(const char p_emo[16][31]) {
    while (TRUE) {
        system("cls");
        srand(time(0));
        draw(p_emo);
        if (kbhit()) {
            if ('n' == getch())
                break;
        }
        Sleep(3);
    }
}

int main() {
    emotions_t E = read_emotion();  //read emotion name
    switch(E) {
        case HAPPY:
            loop(happy);
            break;
        case SAD:
            loop(sad);
            break;
        case GRIMACE:
            loop(grimace);
            break;
        case CRY:
            loop(cry);
            break;
        case ANGRY:
            loop(angry);
            break;
        case NONE:
            printf("Invalid emotion!");
    }
    return 0;
}
