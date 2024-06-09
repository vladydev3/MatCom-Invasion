#ifndef SHIP_H
#define SHIP_H
#include"Shot.h"

typedef struct {
    int x;
    int y;
    int lives;
} Ship;

void DrawShip(Ship* ship);
void DeleteShip(Ship* ship);
void DrawLives(int lives);
void MoveShip(Ship* ship);

#endif /* SHIP_H */