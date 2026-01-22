#include "projet3.h"

int main(void)
{
    struct picture img = new_pic();
    struct color noir = {0, 0, 0};

    sierpinski(&img, 0, img.hauteur - 1, img.largeur, noir);

    save_pic(img, "sierpinski.ppm");

    free(img.pixels);
    return 0;
}

