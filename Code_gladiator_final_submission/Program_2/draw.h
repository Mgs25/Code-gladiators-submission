#ifndef _DRAW_H_
#define _DRAW_H_

// x-axis and y-axis offset to avoid out of bound print
#define X_OFFSET 80
#define Y_OFFSET 10

// Function to generate random x, y co-ordinates within the screen offsets
void fix_points(int* x, int* y) {
    *x = rand() % X_OFFSET;
    *y = rand() % Y_OFFSET;
}

// Function to draw the emotion in the screen
void draw(const char emotion[16][31]) {
    gotoxy(0, 0);
    printf("Press n to stop!");
    
    int x, y;
    
    fix_points(&x, &y);
    gotoxy(x, y); //Move cursor to specified X, Y points
    
    for (int i = 0; i < 16; i++) {
        printf("%s", emotion[i]);
        gotoxy(x, ++y); // y is incremented to allign the lines following the first line
    }
}

#endif
