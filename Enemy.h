#ifndef ENEMY_H
#define ENEMY_H

typedef struct Enemy {
    int x, y; // Posición del enemigo
    int active; // Indica si el enemigo está activo o no
    int speed; // Velocidad de movimiento del enemigo
} Enemy;

void DrawEnemy(Enemy* enemy);
void MoveEnemy(Enemy* enemy);
void DeleteEnemy(Enemy* enemy);

#endif