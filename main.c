#include <ncurses.h> // Incluye la biblioteca ncurses, que proporciona funciones para manipular la pantalla de texto en un entorno de terminal de forma avanzada.

int main() {
    int ch; // Variable para almacenar la tecla presionada por el usuario.
    int x = 10, y = 10; // Coordenadas de la posición inicial de la nave en la pantalla.

    initscr(); // Inicia la ventana de la pantalla.
    start_color(); // Inicia el modo de color.
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK); // Define el par de color 1 como magenta sobre negro.
    curs_set(0); // Oculta el cursor.
    raw(); // Desactiva el buffering de línea.
    keypad(stdscr, TRUE); // Habilita el uso de teclas especiales como las flechas.
    noecho(); // No muestra los caracteres de entrada en la pantalla.
    box(stdscr, 0, 0); // Dibuja un recuadro alrededor de la ventana estándar.

    // Dibuja la nave en la posición inicial.
    attron(COLOR_PAIR(1)); // Aplica el par de color 1.
    mvprintw(y, x,    "              ");
    mvprintw(y+1, x,  " ____/  \\____ ");
    mvprintw(y+2, x,  "|  ___  ___  |");
    mvprintw(y+3, x,  "|_/  o\\/o  \\_|");
    mvprintw(y+4, x,  "     |  |     ");
    mvprintw(y+5, x,  "    /____\\    ");
    attroff(COLOR_PAIR(1)); // Desactiva el par de color 1.
    refresh(); // Actualiza la pantalla.

    while(1) { // Bucle infinito para que el programa siga funcionando hasta que se cierre explícitamente.
        ch = getch(); // Obtiene la tecla presionada por el usuario.

        // Borra la nave anteriormente dibujada en la pantalla.
        mvprintw(y, x,    "                 ");
        mvprintw(y+1, x,  "                 ");
        mvprintw(y+2, x,  "                 ");
        mvprintw(y+3, x,  "                 ");
        mvprintw(y+4, x,  "                 ");
        mvprintw(y+5, x,  "                 ");

        switch(ch) { // Verifica la tecla presionada por el usuario.
            case KEY_UP: // Si la tecla es la flecha arriba.
                if(y > 2) y--; // Mueve la nave hacia arriba si no alcanza el límite superior.
                break;
            case KEY_DOWN: // Si la tecla es la flecha abajo.
                if(y < LINES - 7) y++; // Mueve la nave hacia abajo si no alcanza el límite inferior.
                break;
            case KEY_LEFT: // Si la tecla es la flecha izquierda.
                if(x > 2) x--; // Mueve la nave hacia la izquierda si no alcanza el límite izquierdo.
                break;
            case KEY_RIGHT: // Si la tecla es la flecha derecha.
                if(x < COLS - 18) x++; // Mueve la nave hacia la derecha si no alcanza el límite derecho.
                break;
            default:
                break;
        }

        // Dibuja la nave en la nueva posición.
        attron(COLOR_PAIR(1)); // Aplica el par de color 1.
        mvprintw(y, x,    "              ");
        mvprintw(y+1, x,  " ____/  \\____ ");
        mvprintw(y+2, x,  "|  ___  ___  |");
        mvprintw(y+3, x,  "|_/  o\\/o  \\_|");
        mvprintw(y+4, x,  "     |  |     ");
        mvprintw(y+5, x,  "    /____\\    ");
        attroff(COLOR_PAIR(1)); // Desactiva el par de color 1.
        refresh(); // Actualiza la pantalla.
    }

    endwin(); // Finaliza la ventana de la pantalla.
    return 0; // Retorna 0 para indicar que el programa se ejecutó correctamente.
}
