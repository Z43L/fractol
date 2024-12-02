#include "fractol.h"
int mouse_press(int button, int x, int y, t_data *data) {
    // Validar botones del mouse para zoom
    if (button == 4 || button == 5) {
        double mouse_re = (x - data->ventana.ancho / 2.0) / (data->ventana.ancho / 4.0) / data->fractal.zoom + data->fractal.cx;
        double mouse_im = (y - data->ventana.alto / 2.0) / (data->ventana.alto / 4.0) / data->fractal.zoom + data->fractal.cy;
        
        // Ajustar zoom
        if (button == 4) { // Zoom in
            data->fractal.zoom += 1.5;
        } else if (button == 5) { // Zoom out
            data->fractal.zoom -= 1.5;
        }
        
        
        data->fractal.cx = mouse_re - (x - data->ventana.ancho / 2.0) / (data->ventana.ancho / 4.0) / data->fractal.zoom;
        data->fractal.cy = mouse_im - (y - data->ventana.alto / 2.0) / (data->ventana.alto / 4.0) / data->fractal.zoom;
        

        draw_fractal(data->ventana, data->fractal, &data->comand);
        mlx_put_image_to_window(data->ventana.mlx, data->ventana.win, data->ventana.img, 0, 0);
        printf("Mouse button: %d, x: %d, y: %d, zoom: %d, cx: %f, cy: %f\n", button, x, y, data->fractal.zoom, data->fractal.cx, data->fractal.cy);
    }

    return (0);
}




/*
int mouse_press(int button, int x, int y, mouse *data) {
    if (button == 1) { 
        data->is_dragging = 1;
        data->last_mouse_x = x;
        data->last_mouse_y = y;
    }
    return (0);
}

int mouse_release(int button, int x, int y, mouse *data) {
    if (button == 1) { 
        data->is_dragging = 0; 
    }
    return (0);
}
*/