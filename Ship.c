#include "Ship.h"
#include"Shot.h"
#include <ncurses.h>

void DrawShip(Ship* ship) {
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvprintw(ship->y, ship->x,    "              ");
    mvprintw(ship->y + 1, ship->x, " ____/  \\____ ");
    mvprintw(ship->y + 2, ship->x, "|  ___  ___  |");
    mvprintw(ship->y + 3, ship->x, "|_/  o\\/o  \\_|");
    mvprintw(ship->y + 4, ship->x, "     |  |     ");
    mvprintw(ship->y + 5, ship->x, "    /____\\    ");
    attroff(COLOR_PAIR(1));
    refresh();
}
void DrawLives(int lives)
{
    move(0, 0); // Mueve el cursor a la posición (0, 0)
    clrtoeol(); // Borra la línea actual para evitar residuos de texto previo

    printw("  Life: "); // Muestra el texto "Life:"

    for (int i = 0; i < lives; i++)
    {
        addch(' '); // Añade un espacio para separar los símbolos de vida
        addch(ACS_DIAMOND | A_BOLD | COLOR_PAIR(2)); // Dibuja un corazón
    }

    refresh();
}
void DeleteShip(Ship* ship) {
    mvprintw(ship->y, ship->x,    "                 ");
    mvprintw(ship->y + 1, ship->x, "                 ");
    mvprintw(ship->y + 2, ship->x, "                 ");
    mvprintw(ship->y + 3, ship->x, "                 ");
    mvprintw(ship->y + 4, ship->x, "                 ");
    mvprintw(ship->y + 5, ship->x, "                 ");
}

void MoveShip(Ship* ship) {
    int ch = getch();
    DeleteShip(ship);
    switch(ch) {
        case KEY_UP:
            if(ship->y > 2) ship->y--;
            break;
        case KEY_DOWN:
            if(ship->y < LINES - 7) ship->y++;
            break;
        case KEY_LEFT:
            if(ship->x > 2) ship->x--;
            break;
        case KEY_RIGHT:
            if(ship->x < COLS - 18) ship->x++;
            break;
        default:
            break;
    }
    DrawShip(ship);
}