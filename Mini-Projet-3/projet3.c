#include "projet3.h"

struct picture new_pic(void)
{
    struct picture pic;
    int larg, haut;

    printf("Largeur (pixels) : ");
    if (scanf("%d", &larg) != 1) exit(1);

    printf("Hauteur (pixels) : ");
    if (scanf("%d", &haut) != 1) exit(1);

    if (larg <= 0 || haut <= 0) exit(1);

    pic.largeur = larg;
    pic.hauteur = haut;
    pic.pixels = malloc((size_t)larg * (size_t)haut * sizeof(struct color));
    if (!pic.pixels) exit(1);

    for (int i = 0; i < larg * haut; i++)
    {
        pic.pixels[i].rouge = 255;
        pic.pixels[i].vert = 255;
        pic.pixels[i].bleu = 255;
    }

    return pic;
}

void save_pic(struct picture pic, const char *nom_fichier)
{
    FILE *f = fopen(nom_fichier, "wb");
    if (!f) return;

    fprintf(f, "P6\n%d %d\n255\n", pic.largeur, pic.hauteur);
    fwrite(pic.pixels, sizeof(struct color), (size_t)pic.largeur * (size_t)pic.hauteur, f);

    fclose(f);
}

void set_pixel(struct picture *pic, int x, int y, struct color c)
{
    if (x < 0 || x >= pic->largeur || y < 0 || y >= pic->hauteur) return;
    pic->pixels[y * pic->largeur + x] = c;
}

void draw_line(struct picture *pic, int x1, int y1, int x2, int y2, struct color c)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int n = (int)fmax(abs(dx), abs(dy)) + 1;

    for (int i = 0; i < n; i++)
    {
        double t = (double)i / (double)(n - 1);
        int x = (int)lround(x1 + t * dx);
        int y = (int)lround(y1 + t * dy);
        set_pixel(pic, x, y, c);
    }
}

void sierpinski(struct picture *pic, double x0, double y0, double taille, struct color c)
{
    double x1 = x0 + taille - 1;
    double y1 = y0;
    double x2 = x0 + taille / 2.0;
    double y2 = y0 - taille * sqrt(3.0) / 2.0;

    draw_line(pic, (int)lround(x0), (int)lround(y0), (int)lround(x1), (int)lround(y1), c);
    draw_line(pic, (int)lround(x1), (int)lround(y1), (int)lround(x2), (int)lround(y2), c);
    draw_line(pic, (int)lround(x2), (int)lround(y2), (int)lround(x0), (int)lround(y0), c);

    if (taille < 300) return;

    sierpinski_div(pic, x0, y0, taille, c);
}

void sierpinski_div(struct picture *pic, double x0, double y0, double taille, struct color c)
{
    double t = taille / 2.0;

    sierpinski(pic, x0, y0, t, c);
    sierpinski(pic, x0 + t, y0, t, c);
    sierpinski(pic, x0 + t / 2.0, y0 - taille * sqrt(3.0) / 4.0, t, c);
}
