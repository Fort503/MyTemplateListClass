
# My template list class

Este repositorio contiene una implementación de lista personalizada en C++ utilizando plantillas. Está diseñada para proporcionar funcionalidades similares a la clase `std::list`



## características

- **Plantilla Genérica**: Implementación de la lista utilizando plantillas para soportar cualquier tipo de dato.
- **Operaciones Básicas**: Soporte para operaciones esenciales de lista, como `push_back`, `push_front`, `pop_back`, `pop_front`, `insert` y `clear`.
- **Iteradores**: Clase `iterador` para recorrer la lista de manera eficiente.
- **Métodos de Acceso**: Métodos `front` y `back` para acceder a los primeros y últimos elementos de la lista.
- **Tamaño y Vacío**: Métodos `size` y `empty` para obtener el tamaño de la lista y verificar si está vacía.
- **Conexión de Nodos**: Los nodos están doblemente enlazados, permitiendo movimientos hacia adelante y hacia atrás.

## Comenzando

- **Clona el repositorio**:
    ```
  https://github.com/Fort503/MyTemplateListClass.git
    ```
   

- **Incluye los archivos `Lista.h` y `Nodo.h` en tu proyecto**.

- **Usa la lista en tu código**:
   ```cpp
   #include "Lista.h"

   int main() {
       Lista<int> miLista;
       miLista.push_back(10);
       miLista.push_front(20);
       return 0;
   }
   ```
