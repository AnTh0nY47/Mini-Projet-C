#include "projet1.h"

int main() {
    pixmap img;

    strcpy(img.signature, "P6");
    img.longueur = 600;
    img.hauteur = 400;
    img.intensite_max = 255;

    unsigned char R = 0, G = 0, B = 0;
    unsigned char R2 = 255, G2 = 255, B2 = 255;

    int nbpixels = img.longueur * img.hauteur;
    img.image = malloc(nbpixels * sizeof(pixel));

    int centreX = img.longueur / 2;
    int centreY = img.hauteur / 2;
    int rayonDisque = 100;

    for (int y = 0; y < img.hauteur; y++) {
        for (int x = 0; x < img.longueur; x++) {

            int distanceX = x - centreX;
            int distanceY = y - centreY;

            int positionPixel = y * img.longueur + x;

            if (distanceX*distanceX + distanceY*distanceY <= rayonDisque*rayonDisque) {
                img.image[positionPixel].r = R2;
                img.image[positionPixel].g = G2;
                img.image[positionPixel].b = B2;
            } else {
                img.image[positionPixel].r = R;
                img.image[positionPixel].g = G;
                img.image[positionPixel].b = B;
            }
        }
    }

    FILE *f = fopen("exo2.ppm", "wb");

    fprintf(f, "%s\n%d %d\n%d\n",
            img.signature, img.longueur, img.hauteur, img.intensite_max);

    fwrite(img.image, sizeof(pixel), nbpixels, f);

    fclose(f);
    free(img.image);
}
