#ifndef SHOT_H
#define SHOT_H

typedef struct {
    int x;
    int y;
    int active;
} Shot;

void Fire(int ship_x, int ship_y, Shot* shot);
void MoveShot(Shot* shot,int ship_x,int ship_y);
void DrawShot(Shot* shot);
void DeleteShot(Shot *shot);

#endif /* SHOT_H */