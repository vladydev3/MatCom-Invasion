#include <ncurses.h>

int main() {
    int ch;
    int x = 10, y = 10;

    initscr(); // Inicia la ventana
    raw(); // Desactiva el buffer de línea
    keypad(stdscr, TRUE); // Permite el uso de teclas especiales como las flechas
    noecho(); // No muestra los caracteres de entrada en la pantalla

    mvprintw(y, x, " ^ "); // Dibuja la nave
    mvprintw(y+1, x, "/|\\"); // Dibuja la nave
    mvprintw(y+2, x, "| |"); // Dibuja la nave

    while(1) {
        ch = getch();

        mvprintw(y, x, "   "); // Borra la nave anterior
        mvprintw(y+1, x, "   "); // Borra la nave anterior
        mvprintw(y+2, x, "   "); // Borra la nave anterior

        switch(ch) {
            case KEY_UP:
                if(y > 0) y--;
                break;
            case KEY_DOWN:
                if(y < LINES - 3) y++;
                break;
            case KEY_LEFT:
                if(x > 0) x--;
                break;
            case KEY_RIGHT:
                if(x < COLS - 3) x++;
                break;
            default:
                break;
        }

        mvprintw(y, x, " ^ "); // Dibuja la nave en la nueva posición
        mvprintw(y+1, x, "/|\\"); // Dibuja la nave en la nueva posición
        mvprintw(y+2, x, "| |"); // Dibuja la nave en la nueva posición
        refresh(); // Actualiza la pantalla
    }

    endwin(); // Finaliza la ventana
    return 0;
}