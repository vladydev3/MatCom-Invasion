#include <ncurses.h>

int main() {
    int ch;
    int x = 10, y = 10;

    initscr(); // Inicia la ventana
    start_color(); // Inicia el modo de color
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK); // Define el par de color 1 como magenta sobre negro
    curs_set(0); // Oculta el cursor
    raw(); // Desactiva el buffer de línea
    keypad(stdscr, TRUE); // Permite el uso de teclas especiales como las flechas
    noecho(); // No muestra los caracteres de entrada en la pantalla
    box(stdscr, 0, 0);

     // Dibuja la nave en la nueva posición
        attron(COLOR_PAIR(1)); // Aplica el par de color 1
        mvprintw(y, x,    "              ");
        mvprintw(y+1, x,  " ____/  \\____ ");
        mvprintw(y+2, x,  "|  ___  ___  |");
        mvprintw(y+3, x,  "|_/  o\\/o  \\_|");
        mvprintw(y+4, x,  "     |  |     ");
        mvprintw(y+5, x,  "    /____\\    ");
        attroff(COLOR_PAIR(1)); // Desactiva el par de color 1
        refresh(); // Actualiza la pantalla

    while(1) {
        ch = getch();

        // Borra la nave anterior
        mvprintw(y, x,    "                 ");
        mvprintw(y+1, x,  "                 ");
        mvprintw(y+2, x,  "                 ");
        mvprintw(y+3, x,  "                 ");
        mvprintw(y+4, x,  "                 ");
        mvprintw(y+5, x,  "                 ");

        switch(ch) 
        {   
            case KEY_UP:
                if(y > 2) y--; // límite superior ajustado
                break;
            case KEY_DOWN:
                if(y < LINES - 7) y++; // límite inferior ajustado
                break;
            case KEY_LEFT:
                if(x > 2) x--; // límite izquierdo ajustado
                break;
            case KEY_RIGHT:
                if(x < COLS - 18) x++; // límite derecho ajustado
                break;
            default:
                break;
}
        //Dibuja la nave en la nueva posición
        attron(COLOR_PAIR(1)); // Aplica el par de color 1
        mvprintw(y, x,    "              ");
        mvprintw(y+1, x,  " ____/  \\____ ");
        mvprintw(y+2, x,  "|  _  _  |");
        mvprintw(y+3, x,  "|_/  o\\/o  \\_|");
        mvprintw(y+4, x,  "     |  |     ");
        mvprintw(y+5, x,  "    /____\\    ");
        attroff(COLOR_PAIR(1)); // Desactiva el par de color 1
        refresh(); // Actualiza la pantalla
        

       
    }

    endwin(); // Finaliza la ventana
    return 0;
}