#include "Shot.h"
#include <ncurses.h>
#include <unistd.h>

void Fire(int ship_x, int ship_y, Shot* shot) {
    // Si no hay un disparo activo, creamos uno nuevo
    if (!shot->active) {
        shot->x = ship_x + 5; // Ajusta la posición del disparo al frente de la nave
        shot->y = ship_y - 1; // Ajusta la posición del disparo verticalmente
        shot->active = 1;     // Marca el disparo como activo
    }
}
void MoveShot(Shot* shot, int ship_x, int ship_y) {
    int ch = getch();
    DeleteShot(shot);
    if (ch == ' ') {
        Fire(ship_x, ship_y, shot);
    }
    // Si hay un disparo activo, lo movemos hacia arriba
    if (shot->active==1) {
        shot->y--; // Movemos el disparo hacia arriba
        DrawShot(shot);
        // Si el disparo llega al límite superior de la pantalla, lo desactivamos
        if (shot->y <= 0) {
            shot->active = 0;             // Desactivamos el disparo
        }
    }
}
void DeleteShot(Shot*shot){
    mvprintw(shot->y,shot->x," ");
}
void DrawShot(Shot* shot){
    mvprintw(shot->y, shot->x, "|"); // Dibujamos el disparo
}
