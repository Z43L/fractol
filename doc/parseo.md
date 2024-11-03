# **Parseo para el proyecto Fractol**

El parseo es el proceso de convertir un conjunto de datos de entrada en una estructura de 
datos interna. En el caso de Fractol, el conjunto de datos de entrada son las opciones del 
usuario y los parámetros del fractal.

## **Parámetros de parseo:**

* Tipo de fractal
* Parámetros del fractal
* Configuración de la ventana
* Opciones de guardado y carga de imágenes

## **Estructuras de datos:**

* **Tipo de fractal:** Enumeración o cadena de caracteres
* **Parámetros del fractal:** Estructura con propiedades como el valor complejo c, el valor 
real iteraciones, etc.
* **Configuración de la ventana:** Estructura con propiedades como el ancho, el alto, la 
posición x, la posición y, etc.
* **Opciones de guardado y carga de imágenes:** Estructura con propiedades como el nombre del 
archivo, la ruta del archivo, etc.

## **Algoritmo de parseo:**

1. **Lectura de la entrada:** Se utiliza una función como `fgets()` para leer las opciones 
del usuario desde la entrada estándar.
2. **División de la entrada:** Se utiliza una función como `strtok()` para dividir la entrada 
en tokens separados por espacios o caracteres especiales.
3. **Mapping de tokens:** Se utiliza una estructura de datos como un mapa para mapear los 
tokens a los valores correspondiente.
4. **Validación de datos:** Se verifica que los valores leídos sean válidos y del tipo 
correcto.
5. **Creación de estructuras de datos:** Se crea la estructura de datos correspondiente para 
el fractal, la configuración de la ventana y las opciones de guardado y carga de imágenes.

**estructuras**

```c
typedef enum {
    JULIA,
    MANDELBROT,
    SIERPINSKI,
    SNOWFLAKE
} TipoFractal;

typedef struct {
    TipoFractal tipo;
    double c;
    int iteraciones;
} Fractal;

typedef struct {
    int ancho;
    int alto;
    int posx;
    int posy;
} Ventana;

```
