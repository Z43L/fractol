#include "fractol.h"


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
            
            int red = (int)(255 * (float)inter / fractal.iteraciones);
            int green = (int)(128 * (float)inter / fractal.iteraciones);
            int blue = (int)(64 * (float)inter / fractal.iteraciones);
            int pixel_color = (red << 16) | (green << 8) | blue;
           

            // Escribe el color en el buffer
            int index = (y * ventana.size_line) + (x * (ventana.bpp / 8));
            ventana.data[index] = pixel_color & 0xFF;            // Azul
            ventana.data[index + 1] = (pixel_color >> 8) & 0xFF; // Verde
            ventana.data[index + 2] = (pixel_color >> 16) & 0xFF; // Rojo
        }
    }
}



