#include "fractol.h"

int get_psychedelic_color(int iteration, int max_iteration, double time) {
    double t = (double)iteration / max_iteration;
    int r = (int)(sin(0.16 * time + 5 * t) * 127 + 128);
    int g = (int)(sin(0.16 * time + 5 * t + 2) * 127 + 128);
    int b = (int)(sin(0.16 * time + 5 * t + 4) * 127 + 128);
    return (r << 16) | (g << 8) | b;
}


void draw_fractal(Ventana ventana, Fractal fractal,comand *comand) {
    for (int y = 0; y < ventana.alto; y++) {
        for (int x = 0; x < ventana.ancho; x++) {
            // Mapea píxel al plano complejo
            fractal.cx = (x - ventana.ancho / 2.0) * 4.0 / ventana.ancho / fractal.zoom + fractal.offset;
            fractal.cy = (y - ventana.alto / 2.0) * 4.0 / ventana.alto / fractal.zoom + fractal.offset;

            // Calcula iteraciones
            int inter = 0;
            if (ft_strncmp(comand->type.JULIA, "JULIA", ft_strlen("JULIA")) == 0) {
                inter = julia(fractal, fractal.cx, fractal.cy);
            } else if (ft_strncmp(comand->type.MANDELBROT, "MANDELBROT", ft_strlen("MANDELBROT")) == 0) {
                inter = mandelbort(fractal, comand->interaction);
            }
            

            /* // Escala de grises
            int color = (int)(255 * (float)inter / comand->interaction);
            int pixel_color = (color << 16) | (color << 8) | color;
 */
            // Alternativa: Gradiente de colores
            /**
            int red = (int)(255 * (float)inter / fractal.iteraciones);
            int green = (int)(128 * (float)inter / fractal.iteraciones);
            int blue = (int)(64 * (float)inter / fractal.iteraciones);
            int pixel_color = (red << 16) | (green << 8) | blue;
           */

            // Escribe el color en el buffer
            int index = (y * ventana.size_line) + (x * (ventana.bpp / 8));
            ventana.data[index] = get_psychedelic_color(inter,MAX_ITER, 7);
            ventana.data[index + 1] = get_psychedelic_color(inter,MAX_ITER, 15);
            ventana.data[index + 2] = get_psychedelic_color(inter,MAX_ITER, 5);
        }
    }
}



