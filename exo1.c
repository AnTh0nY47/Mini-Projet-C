#include "projet1.h"

int main() {
    pixmap img;

    strcpy(img.signature, "P6");
    img.longueur = 10;
    img.hauteur = 10;
    img.intensite_max = 255;

    unsigned char R = 0, G = 255, B = 0;

    int nb_pixels = img.longueur * img.hauteur;
    img.image = malloc(nb_pixels * sizeof(pixel));
    if (img.image == NULL) {
        printf("Erreur malloc\n");
        return 1;
    }

    for (int i = 0; i < nb_pixels; i++) {
        img.image[i].r = R;
        img.image[i].g = G;
        img.image[i].b = B;
    }

    FILE *f = fopen("exo1.ppm", "wb");
    if (f == NULL) {
        printf("Erreur ouverture fichier\n");
        free(img.image);
        return 1;
    }

    fprintf(f, "%s\n%d %d\n%d\n",
            img.signature, img.longueur, img.hauteur, img.intensite_max);

    fwrite(img.image, sizeof(pixel), nb_pixels, f);

    fclose(f);
    free(img.image);
