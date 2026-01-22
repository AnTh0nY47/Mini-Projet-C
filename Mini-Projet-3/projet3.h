#ifndef PROJET3_H
#define PROJET3_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct color {
    unsigned char rouge;
    unsigned char vert;
    unsigned char bleu;
};

struct picture {
    int largeur;
    int hauteur;
    struct color *pixels;
};

struct picture new_pic(void);

void save_pic(struct picture pic, const char *nom_fichier);
void set_pixel(struct picture *pic, int x, int y, struct color c);
void draw_line(struct picture *pic, int x1, int y1, int x2, int y2, struct color c);

void sierpinski(struct picture *pic, double x0, double y0, double taille, struct color c);
void sierpinski_div(struct picture *pic, double x0, double y0, double taille, struct color c);

#endif
