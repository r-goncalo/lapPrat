#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef enum { LINE, CIRCLE, RECTANGLE } ShapeKind ;
typedef struct { double x, y; } Point;
typedef struct { Point p1, p2; } Line;
typedef struct { Point centre; double radius; } Circle;
typedef struct { Point top_left; double width, height; } Rectangle;

typedef struct {   // Isto é um tipo SOMA, programado com a ajuda duma UNION
    ShapeKind kind;
    int color;
    union {
        Line line; 
        Circle circle;
        Rectangle rectangle; 
    } u;
} Shape;

Point point(double x, double y) // construtor de pontos
{
    Point p = {x, y};
    return p;
}

Shape line(Point p1, Point p2, int color) // construtor de linhas
{
    Line l = {p1, p2};
    Shape s = {LINE, color};
    s.u.line = l;
    return s;
}

int main(void)
{
    Shape c = circle(point(0,0), 1, 99);
    printf("%f\n", area(c));
    Shape t = triangle(point(0,0), point(5,10), point(10,5), 99);
    printf("%f\n", area(t));
    return 0;
}
