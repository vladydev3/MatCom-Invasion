#include <ncurses.h> // Incluye la biblioteca ncurses, que proporciona funciones para manipular la pantalla de texto en un entorno de terminal de forma avanzada.
#include "Ship.h"

int main() {
    int x=10,y=10;
    // Inicializa ncurses
    initscr(); // Inicia la ventana de la pantalla.
    start_color(); // Inicia el modo de color.
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK); // Define el par de color 1 como magenta sobre negro.
    init_pair(2, COLOR_RED, COLOR_BLACK); // Define el par de color 2 como rojo sobre negro para los corazones
    curs_set(0); // Oculta el cursor.
    raw(); // Desactiva el buffering de línea.
    keypad(stdscr, TRUE); // Habilita el uso de teclas especiales como las flechas.
    noecho(); // No muestra los caracteres de entrada en la pantalla.
    // Inicializa la nave
    Ship ship = {x, y, 3}; // Posición inicial y vidas iniciales
    // Dibuja la nave y las vidas iniciales
    DrawShip(&ship);
    DrawLives(ship.lives);
    // Mueve la nave
    MoveShip(&ship);
    // Finaliza ncurses
    endwin();
    return 0; // Retorna 0 para indicar que el programa se ejecutó correctamente.
}