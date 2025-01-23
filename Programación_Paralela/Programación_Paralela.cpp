// Programación_Paralela.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>  // Incluye la librería estándar para entrada y salida de datos.
#include <omp.h>     // Incluye la librería OpenMP para implementar paralelismo en el programa.

#define N 1000        // Define una constante `N` que representa el tamaño de los arreglos.
#define chunk 100     // Define una constante `chunk` que indica el tamaño de los bloques de trabajo para OpenMP.
#define mostrar 10    // Define una constante `mostrar` que indica cuántos elementos se imprimirán de los arreglos.

void imprimeArreglo(float* d);  // Declaración de una función que imprime los primeros `mostrar` elementos de un arreglo.

int main() {
    std::cout << "Sumando Arreglos en Paralelo!\n";  // Muestra un mensaje inicial para indicar el propósito del programa.

    float a[N], b[N], c[N];  // Declara tres arreglos de tipo `float` con `N` elementos cada uno.
    int i;                   // Declara una variable entera `i` que se usará como índice en los bucles.

    // Inicializa los arreglos `a` y `b` con valores calculados en un bucle.
    for (i = 0; i < N; i++) {      // Itera desde 0 hasta `N-1` para llenar los arreglos.
        a[i] = i * 10;             // Asigna a `a[i]` el valor del índice `i` multiplicado por 10.
        b[i] = (i + 3) * 3.7;      // Asigna a `b[i]` un valor calculado según la fórmula `(i + 3) * 3.7`.
    }
    int pedazos = chunk;           // Guarda el valor de `chunk` en la variable `pedazos`, que será usada en OpenMP.

    // Sección paralela: realiza la suma de los arreglos `a` y `b` en paralelo, almacenando el resultado en `c`.
#pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
    // `omp parallel for`: Indica que el siguiente bucle `for` se ejecutará en paralelo usando múltiples hilos.
    // `shared(a, b, c, pedazos)`: Declara que las variables `a`, `b`, `c` y `pedazos` serán compartidas por todos los hilos.
    // `private(i)`: Declara que cada hilo tendrá su propia copia privada de la variable `i`.
    // `schedule(static, pedazos)`: Divide las iteraciones del bucle en bloques de tamaño `pedazos` y las asigna a los hilos.

    for (i = 0; i < N; i++)        // Itera desde 0 hasta `N-1`, dividiendo las iteraciones entre los hilos.
        c[i] = a[i] + b[i];        // Calcula la suma de `a[i]` y `b[i]` y la guarda en `c[i]`.

    // Imprime los primeros `mostrar` valores del arreglo `a`.
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);             // Llama a la función `imprimeArreglo` para imprimir los valores de `a`.

    // Imprime los primeros `mostrar` valores del arreglo `b`.
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);             // Llama a la función `imprimeArreglo` para imprimir los valores de `b`.

    // Imprime los primeros `mostrar` valores del arreglo `c`.
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);             // Llama a la función `imprimeArreglo` para imprimir los valores de `c`.
}

// Implementación de la función `imprimeArreglo` que imprime los primeros `mostrar` valores de un arreglo.
void imprimeArreglo(float* d) {         // Define una función que recibe un puntero a un arreglo de tipo `float`.
    for (int x = 0; x < mostrar; x++)   // Itera desde 0 hasta `mostrar-1` para recorrer los primeros elementos.
        std::cout << d[x] << " - ";     // Imprime el valor actual del arreglo seguido de un separador (" - ").
    std::cout << std::endl;             // Finaliza la línea de impresión con un salto de línea.
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
