#include <ncurses.h>
#include "Ship.h"
#include "Shot.h"
#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_ENEMIES 3

// Estructura para pasar datos a la función del hilo
typedef struct {
    Ship *ship;
    Shot *shot;
    Enemy *enemies;
} ThreadData;

// Función del hilo para mover los enemigos
void *moveEnemies(void *data) {
    Enemy *enemies = ((ThreadData *)data)->enemies;
    while (1) {
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].active) {
                MoveEnemy(&enemies[i]);
            }
        }
        usleep(50000); // Pequeña pausa para limitar la velocidad del movimiento
    }
    return NULL;
}


void *moveShip(void *data) {
    Ship *ship = ((ThreadData *)data)->ship;
    while (1) {
        MoveShip(ship);
        usleep(50000); // Pequeña pausa para limitar la velocidad del movimiento
    }
    return NULL;
}

// Función del hilo para mover el disparo
void *moveShot(void *data) {
    Shot *shot = ((ThreadData *)data)->shot;
    Ship *ship= ((ThreadData *)data)->ship;
    while (1) {
        Fire(ship->x,ship->y,shot);
        MoveShot(shot);
        usleep(50000); // Pequeña pausa para limitar la velocidad del movimiento
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    Enemy enemies[MAX_ENEMIES];
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].x = i * 10;
        enemies[i].y = 0;
        enemies[i].active = 1;
    }

    int x = 10, y = 10;
    initscr();
    noecho();
    cbreak();
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    curs_set(0);
    raw();
    keypad(stdscr, TRUE);

    Ship ship = {x, y, 3};
    Shot shot = {0, 0, 0};

    // Crear estructuras para pasar datos a las funciones del hilo
    ThreadData enemyThreadData = {NULL, NULL, enemies};
    ThreadData shipThreadData = {&ship, NULL, NULL};
    ThreadData shotThreadData = {&ship, &shot, NULL};

    pthread_t enemiesThread, shipThread, shotThread;

    clear();
    DrawShip(&ship);
    DrawLives(ship.lives);

    // Crear hilos para mover enemigos, nave y disparo
    pthread_create(&enemiesThread, NULL, moveEnemies, (void *)&enemyThreadData);
    pthread_create(&shipThread, NULL, moveShip, (void *)&shipThreadData);
    pthread_create(&shotThread, NULL, moveShot, (void *)&shotThreadData);

    while (1) {
        refresh();
        usleep(50000); // Pequeña pausa para limitar la velocidad del bucle principal
    }

    // Esperar a que los hilos terminen (esto nunca se ejecutará)
    pthread_join(enemiesThread, NULL);
    pthread_join(shipThread, NULL);
    pthread_join(shotThread, NULL);

    endwin();
    return 0;
}