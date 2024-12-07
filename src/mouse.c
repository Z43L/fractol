#include "fractol.h"
int mouse_press(int button, int x, int y, t_data *data) {
    // Calcula las coordenadas del mouse en el plano complejo
    double mouse_re = data->fractal.cx + (x - data->ventana.ancho / 2.0) * (4.0 / data->ventana.ancho) / data->fractal.zoom;
    double mouse_im = data->fractal.cy + (y - data->ventana.alto / 2.0) * (4.0 / data->ventana.alto) / data->fractal.zoom;

    // Ajusta el zoom
    if (button == 4) { // Zoom in
        data->fractal.zoom *= 1.5;
    } else if (button == 5) { // Zoom out
        data->fractal.zoom /= 1.5;
        if (data->fractal.zoom < 1.0) { 
            data->fractal.zoom = 1.0; // Limitar zoom mínimo
        }
    }

    // Recalcula el centro para centrar el zoom en el cursor
    if (data->fractal.zoom > 1.0) {
        data->fractal.cx = mouse_re - (x - data->ventana.ancho / 2.0) * (4.0 / data->ventana.ancho) / data->fractal.zoom;
        data->fractal.cy = mouse_im - (y - data->ventana.alto / 2.0) * (4.0 / data->ventana.alto) / data->fractal.zoom;
    } else {
        // Si el zoom es mínimo, restaurar coordenadas iniciales
        data->fractal.cx = -0.5;
        data->fractal.cy = 0.0;
    }

    // Depuración
    printf("Mouse button: %d, x: %d, y: %d, zoom: %f, cx: %f, cy: %f\n",
           button, x, y, data->fractal.zoom, data->fractal.cx, data->fractal.cy);

    // Redibujar el fractal
    redrawing(data);
    return 0;
}


int handle_key(int keycode, t_data *data) {
    if (keycode == 65307) { // Código para la tecla ESC en Linux (53 en macOS)
        close_program(data);
    }
    return 0;
}
