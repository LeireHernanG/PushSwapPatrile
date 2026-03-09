_Este proyecto ha sido creado como parte del currículo de 42 por lhernan-, pmieres-._
## Push_swap
### Descripción
El proyecto Push_swap consiste en ordenar una lista de números enteros utilizando dos stacks (a y b) y un conjunto limitado de operaciones, con el objetivo de minimizar el número de acciones realizadas. El programa principal, push_swap, recibe la lista inicial en el stack a y genera la secuencia más corta de instrucciones para ordenarla en orden ascendente, dejando el número más pequeño en la cima.

Este proyecto explora la complejidad algorítmica al implementar múltiples estrategias de ordenación con diferentes complejidades (O(n²), O(n√n), O(n log n) y una adaptativa basada en el índice de desorden). Se enfoca en elegir el algoritmo óptimo según el nivel de desorden de la entrada, demostrando cómo la selección impacta en el rendimiento.

Es un proyecto en grupo realizado por dos personas, donde ambos contribuimos en el diseño, implementación y depuración de los algoritmos, el manejo de errores y el modo benchmark. lhernan- se enfocó principalmente en los algoritmos simple y adaptativo, mientras que pmieres- trabajó en los algoritmos medio y complejo, y ambos colaboramos en la integración y pruebas.

## Instrucciones
### Compilación

Ejecuta make para compilar el programa push_swap.c Esto generará el ejecutable.

### Libreria
## Funciones

### Gestión de la pila

| Función | Descripción |
|--------|-------------|
| `ft_lstadd_back_st` | Añade un nodo al final de la lista que representa la pila. |
| `ft_ini_stack` | Inicializa un nuevo nodo de la pila con un valor y su posición. |
| `ft_ini_total_moves` | Inicializa la estructura que guarda el total de movimientos realizados. |
| `ft_lstlast_st` | Devuelve el último nodo de la pila. |
| `ft_lstsize_st` | Devuelve el número de elementos en la pila. |
| `ft_lstclear_st` | Libera la memoria y limpia completamente la pila. |

### Validación y utilidades

| Función | Descripción |
|--------|-------------|
| `ft_rightorder` | Comprueba si la pila ya está ordenada. |
| `control_errors` | Valida los argumentos del programa y detecta posibles errores. |
| `free_mat` | Libera la memoria de una matriz de strings. |
| `fill_stack` | Parsea los argumentos de entrada y rellena la pila con los valores. |
| `compute_disorder` | Calcula una métrica de desorden para ayudar a elegir el algoritmo de ordenación. |
| `ft_set_zero` | Reinicia o ajusta los valores/posiciones de la pila. |
| `ft_sqrt` | Calcula la raíz cuadrada entera de un número. |
| `ft_benchmark` | Muestra información de rendimiento del algoritmo ejecutado. |

### Operaciones de pila

| Función | Descripción |
|--------|-------------|
| `ft_sa` | Intercambia los dos primeros elementos de la pila **a**. |
| `ft_sb` | Intercambia los dos primeros elementos de la pila **b**. |
| `ft_pa` | Mueve el elemento superior de la pila **b** a la pila **a**. |
| `ft_pb` | Mueve el elemento superior de la pila **a** a la pila **b**. |
| `ft_ra` | Rota la pila **a** hacia arriba (el primer elemento pasa al final). |
| `ft_rb` | Rota la pila **b** hacia arriba. |
| `ft_rra` | Rota la pila **a** en sentido inverso (el último elemento pasa al principio). |
| `ft_rrb` | Rota la pila **b** en sentido inverso. |

### Algoritmos de ordenación

| Función | Descripción |
|--------|-------------|
| `ft_radix` | Ordena la pila utilizando el algoritmo **Radix Sort**. |
| `ft_chunkorder` | Ordena los elementos utilizando una estrategia basada en **chunks**. |
| `ft_adaptive` | Selecciona dinámicamente el algoritmo de ordenación según el nivel de desorden. |
| `ft_simpleorder` | Algoritmo básico de ordenación. |
| `ft_fivenum` | Algoritmo optimizado para ordenar **cinco números**. |
| `ft_simple` | Método de ordenación simple para pilas pequeñas. |
### Ejecución

- Uso básico: ./push_swap [selector] [números]
Los números son la lista inicial del stack a (el primero es la cima).
- Selectores opcionales:
    1. simple: Fuerza el algoritmo O(n²).
    2. medium: Fuerza el algoritmo O(n√n).
    3. complex: Fuerza el algoritmo O(n log n).
    4. adaptive: Fuerza el algoritmo adaptativo (por defecto si no se especifica).
    - bench: Muestra: (índice de desorden, estrategia, total de operaciones y conteo por tipo).

- Ejemplos:
    - ./push_swap 2 1 3 6 5 8 (usa adaptativo por defecto).
    - ./push_swap --simple 4 67 3 87 23.
    - ./push_swap --bench --complex $(shuf -i 0-99 -n 100) (con benchmark).

### En caso de error 
- (duplicados, no enteros, etc.), imprime "Error" en stderr.

### Para verificar

- ./push_swap [args] | ./checker [args] (debe imprimir OK si ordena correctamente).

#### Ejemplos de uso

- Ordenación básica:
    
    text$ ./push_swap 2 1 3 6 5 8

    sa
    pb
    ra
    pb
    ra
    pb
    pa
    pa
    pa

- Con benchmark:

    text$ ARG="4 67 3 87 23"; 
    
    ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker $ARG

    OK

    $ cat bench.txt

    [bench] disorder: 40.00%
    [bench] strategy: Adaptive / O(n√n)
    [bench] total_ops: 13
    [bench] sa :  0  sb :  0  pa :  5  pb :  5
    [bench] ra :  2  rb :  1   rra : 0   rrb : 0
    
- Manejo de errores:
    
    text$ ./push_swap --adaptive 0 one 2 3
    
    Error

- Para grandes inputs:

    text$ shuf -i 0-9999 -n 500 > args.txt ; 
    
    ./push_swap $(cat args.txt)

## Algoritmos
Implementamos cuatro estrategias como requerido, justificadas por su complejidad y adaptabilidad al modelo de Push_swap.
### Algoritmo Simple (O(n²)): Adaptación de Bubble Sort y Selection Sort

- Descripción: En ft_simple.c, usamos una variante de bubble sort: iteramos el stack, intercambiamos si el actual > siguiente (sa), y rotamos (ra). Para casos pequeños o alternativos, en ft_simplen.c usamos selection sort: empujamos todo a b, luego extraemos el máximo repetidamente a a.
- Justificación: Elegido por su simplicidad. Para bajos desórdenes, bubble se aproxima a O(n) en práctica (pocas swaps). Complejidad worst-case O(n²) en operaciones (cada iteración puede requerir n rotaciones/swaps).

### Algoritmo Intermedio (O(n√n)): Orden por Chunks

- Descripción: En ft_medium.c, dividimos en √n chunks por posición indexada. Empujamos chunks a b, ordenando al final extrayendo máximos.
- Justificación: Proporciona un balance entre simple y complejo. Dividir en √n reduce comparaciones/rotaciones. Usado para desórdenes medios..

### Algoritmo Complejo (O(n log n)): Radix Sort (LSD)

- Descripción: En ft_complex.c, indexamos posiciones, luego ordenamos por bits (de 0 a log n), empujando a b si bit=0, rotando si 1, y volviendo.
- Justificación: Eficiente para altos desórdenes, ya que no depende de comparaciones directas. Adaptado a stacks usando bits para particiones.

### Algoritmo Adaptativo

- Descripción: En ft_adaptive.c, calculamos desorden (número de inversiones / pares totales). Umbrales: <0.2 usa simple (bubble/selection), [0.2, 0.5) usa chunk, >=0.5 usa radix. Para n<5, caso especial.
- Justificación: Umbrales basados en pruebas: <0.2 (casi ordenado) favorece bubble (cerca O(n)); 0.2-0.5 usa chunk para balance; >=0.5 radix para worst-case. Justificado por rendimiento: en bajos desórdenes, algoritmos simples evitan overhead; en altos, complejos minimizan ops.

## Recursos
Referencias

- Google : Sorting algorithm - Visión general de algoritmos de ordenación.
Radix sort explanation - Detalles sobre radix adaptado a stacks.
- Push_swap tutorial - Guía para implementar en stacks.
Inversion count for disorder - Cálculo de desorden via inversiones.

 #### Uso de IA

Usamos IA (como ChatGPT/Grok) para :
- testers
- En depuración: sugerencias para fixing bugs en rotaciones y indexing.
- No se usó para código principal; revisamos y reescribimos todo manualmente para comprensión total.
- Para el README: IA ayudó a estructurar y redactar secciones, pero contenido basado en nuestro trabajo.


ARG=$(shuf -i 1-200 -n 50 | tr '\n' ' ')
./push_swap $ARG | tee ops.txt | ./checker_linux $ARG
echo "Operaciones usadas:" $(wc -l < ops.txt)

### PRUEBAS 100 num
### Generas la lista una vez
ARG=$(shuf -i 1-200 -n 50 | tr '\n' ' ')
echo $ARG > input.txt

### Cada prueba usa la misma lista
ARG=$(cat input.txt)
./push_swap $ARG | tee ops.txt | ./checker_linux $ARG
echo "Operaciones usadas:" $(wc -l < ops.txt)