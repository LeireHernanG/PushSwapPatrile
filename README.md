_Este proyecto ha sido creado como parte del currículo de 42 por pmieres- y lhernan-_
# Push_swap
## 📋 Descripción del proyecto

**Push_swap** consiste en ordenar una lista de números enteros utilizando **dos stacks** (`a` y `b`) y un conjunto muy limitado de operaciones. El objetivo es generar la secuencia **más corta posible** de instrucciones para dejar la pila `a` ordenada en orden ascendente (el número más pequeño en la cima).

Características principales del proyecto:

- Múltiples algoritmos con diferentes complejidades: **O(n²)**, **O(n√n)**, **O(n log n)** y uno **adaptativo**
- Selección inteligente del algoritmo según el **grado de desorden** de la entrada
- Sistema de benchmark integrado para medir rendimiento
- Manejo estricto de errores (duplicados, no enteros, overflow, etc.)


## 🚀 Compilación

```bash
make          # Compila push_swap
make clean    #Limpia todo
make fclean   #Limpia los .o
make re       # Limpia y vuelve hacer los .o y el ejecutable
```
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
| `ft_orderthree` | Algoritmo optimizado para ordenar **cinco números**. |
| `ft_simple` | Método de ordenación simple para pilas pequeñas. |

### Ejecución

- Uso básico:
            
            ./push_swap [selector] [números]

Los números son la lista inicial del stack a (el primero es la cima).
- Selectores opcionales:
    1. **Simple**: Fuerza el algoritmo O(n²).
    2. **Medium**: Fuerza el algoritmo O(n√n).
    3. **Complex**: Fuerza el algoritmo O(n log n).
    4. **Adaptive**: Fuerza el algoritmo adaptativo (por defecto si no se especifica).
    - **Bench**: Muestra: (índice de desorden, estrategia, total de operaciones y conteo por tipo).

```bash
# Uso básico (usa adaptativo por defecto)
./push_swap 2 1 3 6 5 8

# Forzar algoritmo simple
./push_swap --simple 4 67 3 87 23

# Con benchmark + números aleatorios
./push_swap --bench --complex $(shuf -i 0-99 -n 100)

# Benchmark + checker en una línea
ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG | ./checker $ARG

### En caso de error 
- (duplicados, no enteros, etc.), imprime "Error" en stderr.

### Para verificar

- ./push_swap [args] | ./checker [args] (debe imprimir OK si ordena correctamente).
```

## Benchmarking y Análisis

Utiliza los flags --bench y --adaptive para obtener métricas detalladas sobre la eficiencia del algoritmo y verificar la ordenación con el checker.

Definir argumentos y ejecutar con métricas
```bash
$ ARG="4 67 3 87 23"
$ ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker $ARG
OK
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa:0  sb:0  pa:5  pb:5
[bench] ra:2  rb:1  rra:0  rrb:0
```
## Algoritmos
Implementamos cuatro estrategias, justificadas por su complejidad y adaptabilidad al modelo de Push_swap.

### Algoritmo Simple (O(n²)): Adaptación de Bubble Sort y Selection Sort

- **Descripción**: En ft_simple.c, usamos una variante de bubble sort: iteramos el stack, intercambiamos si el actual > siguiente (sa), y rotamos (ra). Para casos pequeños o alternativos, en ft_simplen.c usamos selection sort: empujamos todo a b, luego extraemos el máximo repetidamente a a.
- **Justificación**: Elegido por su simplicidad. Para bajos desórdenes, bubble se aproxima a O(n) en práctica (pocas swaps). Complejidad worst-case O(n²) en operaciones (cada iteración puede requerir n rotaciones/swaps).

### Algoritmo Intermedio (O(n√n)): Orden por Chunks

- **Descripción**: En ft_medium.c, dividimos en √n chunks por posición indexada. Empujamos chunks a b, ordenando al final extrayendo máximos.
- **Justificación**: Proporciona un balance entre simple y complejo. Dividir en √n reduce comparaciones/rotaciones. Usado para desórdenes medios..

### Algoritmo Complejo (O(n log n)): Radix Sort (LSD)

- **Descripción**: En ft_complex.c, indexamos posiciones, luego ordenamos por bits (de 0 a log n), empujando a b si bit=0, rotando si 1, y volviendo.
- **Justificación**: Eficiente para altos desórdenes, ya que no depende de comparaciones directas. Adaptado a stacks usando bits para particiones.

### Algoritmo Adaptativo

- **Descripción**: En ft_adaptive.c, calculamos desorden (número de inversiones / pares totales). 
    -  Umbrales: 
        - <0.2 usa simple
        - 0.2 <x< 0.5 usa chunk 
        - x<0.5 usa radix

## Recursos
Referencias
- Google : 
    - Sorting algorithm 
    - Visión general de algoritmos de ordenación.
    - Radix sort explanation 
    - Detalles sobre radix adaptado a stacks.
    - Push_swap tutorial - Guía para implementar en stacks.
 #### Uso de IA

Usamos IA para :
- testers
- En depuración: sugerencias para fixing bugs en rotaciones y indexing.
- No se usó para código principal; revisamos y reescribimos todo manualmente para comprensión total.
- Para el README: IA ayudó a estructurar y redactar secciones, pero contenido basado en nuestro trabajo.

## Prubas para la correcion:
#### Generas la lista una vez
ARG=$(shuf -i 1-200 -n 50 | tr '\n' ' ')
echo $ARG > input.txt

#### Cada prueba usa la misma lista
ARG=$(cat input.txt)
./push_swap $ARG | tee ops.txt | ./checker_linux $ARG
echo "Operaciones usadas:" $(wc -l < ops.txt)
