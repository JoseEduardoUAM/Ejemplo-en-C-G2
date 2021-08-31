#include<iostream>
#include<time.h>

void limpiarLets( int lets [] ){
    for (int i = 0; i < 4; i++){
        lets[i] = 0;
    }
}

void descendenteExclusiva( int lets [] ){
    clock_t inicio = clock();
    clock_t ciclo = clock();
    int posicion = 0;
    while( ( (double)clock() - ciclo ) / CLOCKS_PER_SEC < 5.2 ){
        double verificar = ( (double)clock() - inicio ) / CLOCKS_PER_SEC;
        if( verificar >= 0.2 & verificar <= 0.215 ){ 
            std::cout << lets[0] << " " << lets[1] << " " << lets[2] << " " << lets[3] << "\n";
            int letAnterior = posicion - 1;
            lets[ letAnterior >= 0 ? letAnterior : 0 ] = letAnterior >= 0 ? 0 : lets[0];
            lets[ posicion < 4 ? posicion : 0 ] = posicion < 4 ? 1 : lets[0];
            posicion = posicion < 4 ? posicion + 1 : 0;
            inicio = clock();
        }
    }
}

void ascendenteExclusiva( int lets [] ){
    clock_t inicio = clock();
    clock_t ciclo = clock();
    int posicion = 3;
    while( ( (double)clock() - ciclo ) / CLOCKS_PER_SEC < 5.2 ){
        double verificar = ( (double)clock() - inicio ) / CLOCKS_PER_SEC;
        if( verificar >= 0.2 & verificar <= 0.215 ){ 
            std::cout << lets[0] << " " << lets[1] << " " << lets[2] << " " << lets[3] << "\n";
            int letAnterior = posicion + 1;
            lets[ letAnterior <= 3 ? letAnterior : 3 ] = letAnterior >= 3 ? 0 : lets[3];
            lets[ posicion >= 0 ? posicion : 0 ] = posicion >= 0 ? 1 : lets[0];
            posicion = posicion >= 0 ? posicion - 1 : 3;
            inicio = clock();
        }
    }
}

void descendenteAditivaExclusiva( int lets [] ){
    clock_t inicio = clock();
    clock_t ciclo = clock();
    int posicion = 0;
    while( ( (double)clock() - ciclo ) / CLOCKS_PER_SEC < 5.2 ){
        double verificar = ( (double)clock() - inicio ) / CLOCKS_PER_SEC;
        if( verificar >= 0.2 & verificar <= 0.215 ){ 
            std::cout << lets[0] << " " << lets[1] << " " << lets[2] << " " << lets[3] << "\n";
            if( posicion < 4 ){
                lets[posicion] = 1;
                posicion++;
            }else{
                limpiarLets(lets);
                posicion = 0;
            }
            inicio = clock();
        }
    }
}

void ascendeteAditivaExclusiva( int lets [] ){
    clock_t inicio = clock();
    clock_t ciclo = clock();
    int posicion = 3;
    while( ( (double)clock() - ciclo ) / CLOCKS_PER_SEC < 5.2 ){
        double verificar = ( (double)clock() - inicio ) / CLOCKS_PER_SEC;
        if( verificar >= 0.2 & verificar <= 0.215 ){ 
            std::cout << lets[0] << " " << lets[1] << " " << lets[2] << " " << lets[3] << "\n";
            if( posicion >= 0 ){
                lets[posicion] = 1;
                posicion--;
            }else{
                limpiarLets(lets);
                posicion = 3;
            }
            inicio = clock();
        }
    }
}
