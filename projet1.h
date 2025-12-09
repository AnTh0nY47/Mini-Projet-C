#ifndef projet1_h
#define projet1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
}pixel;

typedef struct {
    
    char signature [3];
    int longueur;
    int hauteur;
    int intensite_max;
    pixel* image;

}pixmap;

struct P {};

#endif