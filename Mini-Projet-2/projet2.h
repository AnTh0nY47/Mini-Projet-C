#ifndef projet2_h
#define projet2_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

typedef struct {
    char signature[3];
    int longueur;
    int hauteur;
    int intensite_max;
    pixel *image;
} pixmap;

typedef struct color {
    char red;
    char green;
    char blue;
} color;

void calcul_bornes(int frame, int total_frames, double *xgauche, double *xdroite, double *yhaut, double *ybas);
void mandelbrot(const char *exo4, double xgauche, double xdroite, double yhaut, double ybas);

#endif
