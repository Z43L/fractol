# fractol

El proyecto Fractol de 42 utiliza la biblioteca minilibx-linux para renderizar fractales. Los 
fractales Julia y Mandelbrot son dos ejemplos de fractales que se pueden dibujar utilizando 
esta biblioteca.

## que es un fractal

Un fractal es una estructura matemática que se parece a sí misma a diferentes escalas. Son 
objetos que poseen una propiedad llamada autosimilaridad, lo que significa que cada parte del 
fractal parece una versión más pequeña del mismo fractal.

**Características de un fractal:**

* **Autosimilaridad:** Se parece a sí mismo a diferentes escalas.
* **Complejidad:** Son estructuras muy complejas a pesar de que solo están compuestas por 
partes simples.
* **Similitud:** Hay una relación de similitud entre diferentes partes del fractal.
* **Iteración:** Se puede generar a través de una secuencia de iteraciones.

**Ejemplos de fractales:**

* Fractal de Julia
* Fractal de Mandelbrot
* Fractal de Sierpinski
* Fractal de snowflake

**Aplicaciones de los fractales:**

Los fractales se pueden encontrar en diferentes áreas, como:

* **Matemáticas:** Análisis numérico, teoría de funciones.
* **Computación:** Imágenes, gráficos por computadora.
* **Biología:** Estructuras microscópicas, patrones de crecimiento.
* **Arte:** Estilos visuales, diseño gráfico.

**Importancia de los fractales:**

Los fractales son ejemplos de estructuras matemáticas que son muy difíciles de describir o 
visualizar. Su complejidad y belleza matemáticas los convierten en objetos de estudio 
fascinantes.

### **Fractales Julia:**

* Es un fractal que se puede dibujar con diferentes parámetros de programa.
* La ecuación del fractal de Julia es:

```
z_n+1 = z_n^2 + c
```

* Donde `z_n` es la iteración actual del fractal, `c` es un parámetro complejo y `z_0` es un 
punto inicial.

### **Fractales Mandelbrot:**

* Es un fractal que se puede dibujar con diferentes parámetros de programa.
* La ecuación del fractal de Mandelbrot es:

```
z_n+1 = z_n^2 + c
```

* Donde `z_n` es la iteración actual del fractal, `c` es un parámetro complejo y `z_0` es un 
punto inicial.

## **Parámetros de programa:**

Cada fractal recibe diferentes parámetros de programa que controlan diferentes aspectos de su 
renderizado, como:

* Tamaño del fractal
* Resolución de la imagen
* Color de los puntos
* Cantidad de iteraciones

El programa Fractol recibe argumentos de línea de comandos que controlan diferentes aspectos 
de su comportamiento. Los argumentos son:

* `--type`: Tipo de fractal a dibujar (julia o mandelbrot).
* `--width`: Ancho de la imagen en píxeles.
* `--height`: Alto de la imagen en píxeles.
* `--iterations`: Cantidad de iteraciones para calcular el fractal.
* `--color`: Color de los puntos del fractal.
* `--x`: Coordenada x del punto inicial.
* `--y`: Coordenada y del punto inicial.

 **Ejemplo:**

```
fractol --type julia --width 800 --height 600 --iterations 1000 --color red --x 0.2 --y 0.6
```

Este comando dibujará un fractal de Julia con un ancho de 800 píxeles, un alto de 600 
píxeles, 1000 iteraciones, un color rojo y un punto inicial en las coordenadas (0.2, 0.6).

## **Checklist de funciones:**

**Generación de fractales:**

* `calcular_fractal_julia()`
* `calcular_fractal_mandelbrot()`
* `calcular_fractal_sierpinski()`
* `calcular_fractal_snowflake()`

**Funciones auxiliares:**

* `iterar_punto()`
* `graficar_pixel()`
* `dibujar_circulo()`
* `dibujar_triangulo()`

**Funciones de interfaz de usuario:**

* `menu_opciones()`
* `ajustar_parametros()`
* `guardar_imagen()`
* `cargar_imagen()`

**Funciones de configuración:**

* `cargar_configuracion()`
* `guardar_configuracion()`

**Funciones de ayuda:**

* `ayuda()`

**Funciones de gráficos:**

* `crear_ventana()`
* `dibujar_ventana()`
* `actualizar_ventana()`

**Funciones de dibujo:**

* `dibujar_fractal()`
* `dibujar_circulo()`
* `dibujar_triangulo()`

**Funciones de manejo de eventos:**

* `manejar_mouse()`
* `manejar_teclado()`

