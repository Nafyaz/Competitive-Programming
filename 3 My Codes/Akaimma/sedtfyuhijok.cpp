// C++ Implementation for drawing line
#include<bits/stdc++.h>
#include <graphics.h>
#include<conio.h>
int main()
{
    // gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file
    int gd = DETECT, gm;
    printf("lol");
    // initgraph initializes the graphics system
    // by loading a graphics driver from disk
    initgraph(&gd, &gm, "C:\\tc\bgi");

    // line for x1, y1, x2, y2
    line(150, 150, 450, 150);

    // line for x1, y1, x2, y2
    line(150, 200, 450, 200);

    // line for x1, y1, x2, y2
    line(150, 250, 450, 250);

    getch();
    printf("lol");

    // closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system .
    closegraph();
}
