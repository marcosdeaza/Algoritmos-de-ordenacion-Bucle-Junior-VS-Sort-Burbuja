#include <iostream>

using namespace std;

int main() {

    // ---------------------------------------------------
    // 1. DECLARACIÓN DE VARIABLES
    // ---------------------------------------------------
    // Defino un array de 10 posiciones (tipo float por si meten decimales)
    float vector_entrada[10]; 
    
    // Necesito dos copias extra para probar los dos métodos sin mezclar
    float vector_mio[10];
    float vector_burbuja[10];
    
    float auxiliar; // Variable auxiliar para hacer los intercambios

    // ---------------------------------------------------
    // 2. ENTRADA DE DATOS
    // ---------------------------------------------------
    cout << "--- PROGRAMA PARA ORDENAR UN VECTOR ---" << endl;
    
    for(int i = 0; i < 10; i++) {
        cout << "Introduce el número " << (i + 1) << ": ";
        cin >> vector_entrada[i];

        // Truco: Copio los datos a los otros vectores aquí mismo
        // Así me ahorro hacer otro bucle 'for' después solo para copiar
        vector_mio[i] = vector_entrada[i];
        vector_burbuja[i] = vector_entrada[i];
    }

    // ---------------------------------------------------
    // PARTE 1: ORDENAR A MI MANERA (Lógica propia)
    // ---------------------------------------------------
    // Mi idea: Busco el número más pequeño de la lista y lo pongo al principio.
    // Luego busco el siguiente más pequeño y lo pongo segundo, etc.
    
    for(int i = 0; i < 9; i++) {
        int pos_menor = i; // Supongo que el primero de la fila es el menor
        
        // Recorro el resto del vector buscando si hay alguno más pequeño
        for(int j = i + 1; j < 10; j++) {
            if(vector_mio[j] < vector_mio[pos_menor]) {
                pos_menor = j; // Encontré uno menor, guardo su posición
            }
        }
        
        // Si encontré uno más pequeño que el actual, hago el cambio
        if(pos_menor != i) {
            auxiliar = vector_mio[i];
            vector_mio[i] = vector_mio[pos_menor];
            vector_mio[pos_menor] = auxiliar;
        }
    }

    // ---------------------------------------------------
    // PARTE 2: ALGORITMO BURBUJA (Investigado)
    // ---------------------------------------------------
    // Según lo investigado, hay que comparar parejas adyacentes.
    // Si el de la izquierda es mayor que el de la derecha, se intercambian.
    // Esto hace que los números grandes "floten" al final.
    
    for(int i = 0; i < 10; i++) {
        // El bucle de dentro recorre el vector
        // Le resto 'i' porque los últimos ya van quedando ordenados en cada pasada
        for(int j = 0; j < 9 - i; j++) {
            
            // Comparo el actual con el siguiente
            if(vector_burbuja[j] > vector_burbuja[j + 1]) {
                // Intercambio manual usando la variable auxiliar
                auxiliar = vector_burbuja[j];
                vector_burbuja[j] = vector_burbuja[j + 1];
                vector_burbuja[j + 1] = auxiliar;
            }
        }
    }

    // ---------------------------------------------------
    // 3. MOSTRAR RESULTADOS
    // ---------------------------------------------------
    cout << endl << "--- RESULTADOS FINALES ---" << endl;

    cout << "Ordenado por mi lógica:  ";
    for(int i = 0; i < 10; i++) {
        cout << vector_mio[i] << " ";
    }
    cout << endl;

    cout << "Ordenado por la Burbuja: ";
    for(int i = 0; i < 10; i++) {
        cout << vector_burbuja[i] << " ";
    }
    cout << endl;

    return 0;
}