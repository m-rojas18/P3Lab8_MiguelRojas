#include <ncurses.h>
#include <iostream>
using namespace std;

int main(){
    initscr();
    cbreak();
    if(!has_colors()){
        endwin();
        printw("La terminal no tiene opcion de mostrar color");
        getch();
        return 1;
    }
    int maximo_y, maximo_x;
    getmaxyx(stdscr, maximo_y, maximo_x);
    WINDOW *ventana = newwin(maximo_y,maximo_x,0,0);
    start_color();
    //Colores
    init_pair(1,COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    init_pair(3, COLOR_YELLOW, COLOR_BLUE);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    //Cambiar color a ventana
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
    
    int x_panel = maximo_x - 6;
    //Crear primera caje que contiene "Control Center"
    WINDOW *panel_1 = newwin(3,x_panel,3,3);
    wbkgd(panel_1, COLOR_PAIR(1));
    attron(COLOR_PAIR(4));
    box(panel_1, 0, 0);
    attroff(COLOR_PAIR(4));
    refresh();
    wrefresh(panel_1);
    wrefresh(ventana);

    //Escribir lo que ve en la caja
    int mitad_panel1_x = ((3 + x_panel )/ 2 ) -11;
    int mitad_panel1_y = (3 + 5 )/ 2;
    attron(COLOR_PAIR(3));
    mvprintw(mitad_panel1_y, mitad_panel1_x ,"YaST2 Control Center");
    attroff(COLOR_PAIR(3));

    //Crear segunda caja
    int y_caja2 = maximo_y - 12;
    WINDOW *panel_2 = newwin(y_caja2,20,8,3);
    wbkgd(panel_2, COLOR_PAIR(1));
    attron(COLOR_PAIR(4));
    box(panel_2, 0, 0);
    attroff(COLOR_PAIR(4));
    refresh();
    wrefresh(panel_2);
    wrefresh(ventana);
    //Color de Palabara Software
    init_pair(5,COLOR_YELLOW, COLOR_CYAN);
    //Color de Resto de Palabras
    init_pair(6, COLOR_WHITE, COLOR_BLUE);
    attron(COLOR_PAIR(5));
    mvprintw(9,4, "Software          ");
    attroff(COLOR_PAIR(5));
    

    attron(COLOR_PAIR(6));
    mvprintw(10, 4, "Hardware");
    mvprintw(11, 4, "System");
    mvprintw(12, 4, "Network Devices");
    mvprintw(13, 4, "Security and Users");
    mvprintw(14, 4, "Misc");
    attroff(COLOR_PAIR(6));


    //Crear Tercera Caja
    int y_caja3 = maximo_y - 12;
    int x_panel2 = x_panel - 23;
    WINDOW *panel_3 = newwin(y_caja3,x_panel2, 8,26);
    wbkgd(panel_3, COLOR_PAIR(1));
    attron(COLOR_PAIR(4));
    box(panel_3, 0, 0);
    attroff(COLOR_PAIR(4));
    refresh();
    wrefresh(panel_3);
    wrefresh(ventana);

    attron(COLOR_PAIR(3));//Color de primera linea en Caja 3
    mvprintw(9, 27, "Patch CD Update");
    attroff(COLOR_PAIR(3));

    //Resto de Info
    attron(COLOR_PAIR(6));
    mvprintw(10, 27, "Installation into Directory");
    mvprintw(11, 27, "Online Update");
    mvprintw(12, 27, "Change Source of Installation");
    mvprintw(13, 27, "System Update");
    attroff(COLOR_PAIR(6));


    int y_comandos_abajo = maximo_y - 3;
    int x_comando_quit = x_panel - 4;
    attron(COLOR_PAIR(3));//Colorear a la H y la Q
    mvprintw(y_comandos_abajo, 5, "H");
    mvprintw(y_comandos_abajo,x_comando_quit + 1, "Q");
    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(6));
    //Escribir resto de [Help]
    mvprintw(y_comandos_abajo, 4, "[");
    mvprintw(y_comandos_abajo, 6, "elp]");
    //Escribir resto de [Quit]
    mvprintw(y_comandos_abajo, x_comando_quit, "[");
    mvprintw(y_comandos_abajo, x_comando_quit + 2, "uit]");
    attroff(COLOR_PAIR(6));

    //Pintar error que salia en negro entre palabras
    attron(COLOR_PAIR(1));
    for (int i = 10; i < x_comando_quit; i++){
        mvprintw(y_comandos_abajo, i, " ");
    }


    move(20,20);
    getch();
    refresh();
    endwin();
    return 0;
}