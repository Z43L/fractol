#include "fractol.h"

int get_psychedelic_color(int iteration, int max_iteration, double time) {
    double t = (double)iteration / max_iteration;
    int r = (int)(sin(0.16 * time + 5 * t) * 127 + 128);
    int g = (int)(sin(0.16 * time + 5 * t + 2) * 127 + 128);
    int b = (int)(sin(0.16 * time + 5 * t + 4) * 127 + 128);
    return (r << 16) | (g << 8) | b;
}

void clear_image(Ventana ventana) {
    int x, y;
    for (y = 0; y < ventana.alto; y++) {
        for (x = 0; x < ventana.ancho; x++) {
            int index = (y * ventana.size_line) + (x * (ventana.bpp / 8));
            ventana.data[index] = 0;       // Azul
            ventana.data[index + 1] = 0;  // Verde
            ventana.data[index + 2] = 0;  // Rojo
        }
    }
}


void draw_fractal(Ventana ventana, Fractal fractal, comand *comand) {
    int x, y;
    y = 0;

    while (y < ventana.alto) {
        x = 0;
        while (x < ventana.ancho) {
            double re = fractal.cx + (x - ventana.ancho / 2.0) / (ventana.ancho / 4.0) / fractal.zoom;
            double im = fractal.cy + (y - ventana.alto / 2.0) / (ventana.alto / 4.0) / fractal.zoom;

            int iter = 0;
            if (ft_strncmp(comand->type.JULIA, "JULIA", ft_strlen("JULIA")) == 0) {
                iter = julia(fractal, re, im);
            } else if (ft_strncmp(comand->type.MANDELBROT, "MANDELBROT", ft_strlen("MANDELBROT")) == 0) {
                iter = mandelbort(fractal, fractal.iteraciones);
            }

            int color = get_psychedelic_color(iter, fractal.iteraciones, fractal.zoom);

            int index = (y * ventana.size_line) + (x * (ventana.bpp / 8));
            ventana.data[index] = color & 0xFF; 
            ventana.data[index + 1] = (color >> 8) & 0xFF;
            ventana.data[index + 2] = (color >> 16) & 0xFF;

            x++;
        }
        y++;
    }
}
