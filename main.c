#include <ncurses.h>
#include "Ship.h"
#include "Shot.h"
#include "Enemy.h"
#include <stdlib.h>
#include <time.h>

int main() {
    #define MAX_ENEMIES 3
    srand(time(NULL));
    Enemy enemies[MAX_ENEMIES];
    // Inicializa los enemigos
    for (int i = 0; i < MAX_ENEMIES; i++) {
    enemies[i].x = i * 10; // Posiciona los enemigos horizontalmente
    enemies[i].y = 0; // Posiciona los enemigos en la parte superior de la pantalla
    enemies[i].active = 1; // Marca los enemigos como activos
    }   

    int x = 10, y = 10;
    // Inicializa ncurses
    initscr();
    noecho();
    cbreak();
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    curs_set(0);
    raw();
    keypad(stdscr, TRUE);
    // Inicializa la nave
    Ship ship = {x, y, 3};
    Shot shot = {0, 0, 0};
    int seleccion = 0;
    int opcion;

    while(1) {
        clear(); // Limpiar la ventana
        mvprintw(1, 1, "  Bienvenido al juego de consola Matcom Invaders");
        
        if(seleccion == 0) attron(A_REVERSE); // Resaltar la opción seleccionada
        mvprintw(2, 1, "Start Game");
        attroff(A_REVERSE);
        
        if(seleccion == 1) attron(A_REVERSE); // Resaltar la opción seleccionada
        mvprintw(3, 1, "About");
        attroff(A_REVERSE);
        
        if(seleccion == 2) attron(A_REVERSE); // Resaltar la opción seleccionada
        mvprintw(4, 1, "Exit");
        attroff(A_REVERSE);

        refresh(); // Actualizar la ventanaf

        opcion = getch(); // Obtener la tecla presionada

        if(opcion == KEY_UP) { // Mover la selección hacia arriba
            seleccion--;
        } 
        else if (opcion == KEY_DOWN) { // Mover la selección hacia abajo
            seleccion++;
        } 
        else if (opcion == 10) { // Si se presiona Enter
            if(seleccion == 0) {
                // Lógica para iniciar el juego
                clear();
                // Dibuja la nave y las vidas iniciales
                DrawShip(&ship);
                DrawLives(ship.lives);
                // Bucle principal del juego
                while (1) {
                    int activeEnemies = 0;
                    for (int i = 0; i < MAX_ENEMIES; i++) {
                        if (enemies[i].active) {
                            activeEnemies++;
                        }
                    }

                    if (activeEnemies == 0 && rand() % 100 < 2) { // chance en % de spawnear un enemigo
                        int i = rand() % MAX_ENEMIES; // elegir un enemigo aleatorio
                        enemies[i].x = rand() % COLS; // posicion aleatoria en x
                        enemies[i].y = 0; // empezar en la parte superior de la pantalla
                        enemies[i].active = 1; // activar el enemigo
                    }

                    // mover y dibujar los enemigos
                    for (int i = 0; i < MAX_ENEMIES; i++) {
                        MoveEnemy(&enemies[i]);
                    }
                    int ch = getch();
                    if (ch==27)
                    {
                        clear();
                        printw("Game Over");
                        refresh();
                        getch();
                        break;
                    }
                    MoveShip(&ship, &shot); // Mueve la nave y controla los disparos
                    MoveShot(&shot,ship.x,ship.y);        // Mueve el disparo  
                    refresh();      
                }   
            }
            if(seleccion == 1) {
                // Lógica para mostrar información del juego
                clear();
                mvprintw(1, 1, "Este es un juego creado para como proyecto final de la asignatura de Sistemas Operativos, es un juego del estilo clasico Alien Invaders");
                refresh();
                getch();
            } 
            if(seleccion == 2) {
                break; // Salir del bucle
            }
        }
        // Verificar límites de selección
        if(seleccion < 0) {
            seleccion = 2;
        } 
        else if (seleccion > 2) {
            seleccion = 0;
        }
    }    
    endwin();
    return 0;
}
