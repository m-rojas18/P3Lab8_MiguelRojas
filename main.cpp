#include <ncurses.h>
#include <iostream>
using namespace std;

int main(){
    initscr();
    if(!has_colors()){
        endwin();
        printw("La terminal no tiene opcion de mostrar color");
        getch();
        return 1;
    }
    int maximo_y, maximo_x;
    getmaxyx(stdscr, maximo_y, maximo_x);
    start_color();
    init_pair(1,COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    WINDOW *ventana = newwin(maximo_y,maximo_x,0,0);
    wbkgd(ventana, COLOR_PAIR(1));
    refresh();
    wrefresh(ventana);

    //Escribir primera linea
    attron(COLOR_PAIR(2));
    printw(" YaST @ g185");
    
    int final_linea = maximo_x - 19;
    for (int i = 11; i < final_linea; i++){
        printw(" ");
    }
    printw("Press F1 for Help ");
    attroff(COLOR_PAIR(2));
    move(20,20);
    getch();
    refresh();

    
    endwin();
    return 0;
}