#include<ncurses.h>
typedef struct 
{
    int x;
    int y;
    int lives;
}Ship;
void DrawLives(int lives)
{
    // Muestra la vida de la nave en la parte superior de la consola como corazones
    move(0, 0); // Mueve el cursor a la posición (0, 0)
    clrtoeol(); // Borra la línea actual para evitar residuos de texto previo

    for (int i = 0; i < lives; i++)
    {
        addch(ACS_DIAMOND | A_BOLD | COLOR_PAIR(2)); // Dibuja un corazón
    }

    refresh();
}
void DrawShip(Ship*ship)
{
    // Dibuja la nave en la posición inicial.
    start_color(); 
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK); // Define el par de color 1 como magenta sobre negro.
    attron(COLOR_PAIR(1)); // Aplica el par de color 1.
    mvprintw(ship->y, ship->x,    "              ");
    mvprintw(ship->y+1, ship->x,  " ____/  \\____ ");
    mvprintw(ship->y+2, ship->x,  "|  ___  ___  |");
    mvprintw(ship->y+3, ship->x,  "|_/  o\\/o  \\_|");
    mvprintw(ship->y+4, ship->x,  "     |  |     ");
    mvprintw(ship->y+5, ship->x,  "    /____\\    ");
    attroff(COLOR_PAIR(1)); // Desactiva el par de color 1.
    refresh(); // Actualiza la pantalla.

}
void DeleteShip(Ship*ship)
{
    // Borra la nave anteriormente dibujada en la pantalla.
        mvprintw(ship->y,ship->x,    "                 ");
        mvprintw(ship->y+1,ship->x,  "                 ");
        mvprintw(ship->y+2,ship->x,  "                 ");
        mvprintw(ship->y+3,ship->x,  "                 ");
        mvprintw(ship->y+4,ship->x,  "                 ");
        mvprintw(ship->y+5,ship->x,  "                 ");
}
void MoveShip(Ship* ship)
{
    
    while (1)
    {
        int ch=getch();
        DeleteShip(ship);
        switch(ch) 
        { // Verifica la tecla presionada por el usuario.
            case KEY_UP: // Si la tecla es la flecha arriba.
                if(ship->y > 2) ship->y--; // Mueve la nave hacia arriba si no alcanza el límite superior.
                break;
            case KEY_DOWN: // Si la tecla es la flecha abajo.
                if(ship->y < LINES - 7) ship->y++; // Mueve la nave hacia abajo si no alcanza el límite inferior.
                break;
            case KEY_LEFT: // Si la tecla es la flecha izquierda.
                if(ship->x > 2) ship->x--; // Mueve la nave hacia la izquierda si no alcanza el límite izquierdo.
                break;
            case KEY_RIGHT: // Si la tecla es la flecha derecha.
                if(ship->x < COLS - 18) ship->x++; // Mueve la nave hacia la derecha si no alcanza el límite derecho.
                break;
            default:
                break;
        }   
        DrawShip(ship);
    }
    
    
}

