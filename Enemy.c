#include "Enemy.h"
#include <ncurses.h>

void DrawEnemy(Enemy* enemy) {
    if (enemy->active) {
        mvprintw(enemy->y, enemy->x, " ^ ");
        mvprintw(enemy->y + 1, enemy->x, "<o>");
        mvprintw(enemy->y + 2, enemy->x, "-^-");
    }
}

void DeleteEnemy(Enemy* enemy) {
    mvprintw(enemy->y, enemy->x, "   ");
    mvprintw(enemy->y + 1, enemy->x, "   ");
    mvprintw(enemy->y + 2, enemy->x, "   ");
}

void MoveEnemy(Enemy* enemy) {
    if (enemy->active) {
        DeleteEnemy(enemy);
        enemy->speed; // Mueve el enemigo hacia abajo
        if (enemy->speed >= 5) { // Mover el enemigo cada 5 frames
            enemy->y++;
            enemy->speed = 0; 
        }
        else {
            enemy->speed++;
        }
        DrawEnemy(enemy);
        // Si el enemigo llega al límite inferior de la pantalla, lo desactiva
        if (enemy->y >= LINES) {
            enemy->active = 0;
        }
    }
}