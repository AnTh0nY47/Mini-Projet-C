#include "projet2.h"

int main()
{
int total_frames = 100;
int frame;

for (frame = 0; frame < total_frames; frame++)
{
double xgauche, xdroite, yhaut, ybas;

calcul_bornes(frame, total_frames, &xgauche, &xdroite, &yhaut, &ybas);

char filename[64];
sprintf(filename, "frame_%03d.ppm", frame);

mandelbrot(filename, xgauche, xdroite, yhaut, ybas);
}

return 0;
}

