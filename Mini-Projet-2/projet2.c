#include "projet2.h"

#define largeur 900
#define hauteur 600
#define maxiter 85

double pixelx(int i, double xgauche, double xdroite)
{
double r;
r = xgauche + (xdroite - xgauche) * i / (largeur - 1);
return r;
}

double pixely(int j, double yhaut, double ybas)
{
double y;
y = yhaut + (ybas - yhaut) * j / (hauteur - 1);
return y;
}

int convergence(double x, double y)
{
double rx = x;
double iy = y;
int k = 0;

while (k < maxiter)
{
double r2 = rx * rx - iy * iy + x;
double i2 = 2 * rx * iy + y;

rx = r2;
iy = i2;

if (rx * rx + iy * iy > 4)
return k + 1;

k = k + 1;
}

return 0;
}

void couleurs(FILE *f, int c)
{
unsigned char r = 0;
unsigned char g = c * 3;
unsigned char b = 255;

fputc(r, f);
fputc(g, f);
fputc(b, f);
}

void calcul_bornes(int frame, int total_frames,
double *xgauche, double *xdroite,
double *yhaut, double *ybas)
{
double centreX = -0.75;
double centreY = 0;
double zoom_initial = 5;
double zoom_final = 2;

double facteur = pow(zoom_final / zoom_initial, (double)frame / total_frames);
double largeurX = zoom_initial * facteur;
double hauteurY = (largeurX * hauteur) / largeur;

*xgauche = centreX - largeurX / 2;
*xdroite = centreX + largeurX / 2;
*yhaut = centreY + hauteurY / 2;
*ybas = centreY - hauteurY / 2;
}

void mandelbrot(const char *exo4,
double xgauche, double xdroite,
double yhaut, double ybas)
{
FILE *f;

f = fopen(exo4, "wb");
fprintf(f, "P6\n%d %d\n255\n", largeur, hauteur);

int j, i;

for (j = 0; j < hauteur; j++)
{
for (i = 0; i < largeur; i++)
{
double x = pixelx(i, xgauche, xdroite);
double y = pixely(j, yhaut, ybas);

int c = convergence(x, y);

couleurs(f, c);
}
}

fclose(f);
}
