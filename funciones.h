#include<iostream>
#include<time.h>

#define tiempoLet 0.2
#define tiempoCiclo 5.0
// Estructura para lets
struct let{
    int numero;
    bool estado; 
};
// Arreglo que almacena e inicializa los lets
let lets[4] = { { 35 , false } , { 36 , false } , { 37 , false } , { 38 , false } };
// Funcion que permite esperar un determinado tiempo para encender los lets
void esperar(){
    clock_t ciclo = clock();
    while( ( (double)clock() - ciclo ) / CLOCKS_PER_SEC < tiempoLet );
}
// Funcion que permite encender los lets
void encenderLets(){
    for( let x : lets ){
        std::cout << x.numero << ":" << x.estado << " ";
    }
    std::cout << "\n";
}
// Funcion que permite colocar a los lets en el estado apagado = false
void limpiarLets(){
    for (int i = 0; i < 4; i++){
        lets[i].estado = false;
    }
}
// Funcion que enciende cada led de forma descendete (de mayor a menor)
void descendenteExclusiva(){
    clock_t ciclo = clock();
    while( ( (double)clock() - ciclo ) / CLOCKS_PER_SEC < tiempoCiclo ){
        for( int i = 0 ; i < 4 ; i++ ){
            lets[i].estado = true;
            encenderLets();
            esperar();
            lets[i].estado = false;
        }
    }
}
// Funcion que enciende cada led de forma descendete (de mayor a menor)
void ascendenteExclusiva(){
    clock_t ciclo = clock();
    while( ( (double)clock() - ciclo ) / CLOCKS_PER_SEC < tiempoCiclo ){
        for( int i = 3 ; i >= 0 ; i-- ){
            lets[i].estado = true;
            encenderLets();
            esperar();
            lets[i].estado = false;
        }
    }
}
// Funcion que enciende cada led de forma descendente Aditiva exclusiva
void descendenteAditivaExclusiva(){
    clock_t ciclo = clock();
    while( ( (double)clock() - ciclo ) / CLOCKS_PER_SEC < tiempoCiclo ){
        for( int i = 0 ; i < 4 ; i++ ){
            lets[i].estado = true;
            encenderLets();
            esperar();            
        }
        limpiarLets();
    }
}
// Funcion que enciende cada led de forma ascendente Aditiva exclusiva
void ascendenteAditivaExclusiva(){
    clock_t ciclo = clock();
    while( ( (double)clock() - ciclo ) / CLOCKS_PER_SEC < tiempoCiclo ){
        for( int i = 3 ; i >= 0 ; i-- ){
            lets[i].estado = true;
            encenderLets();
            esperar();            
        }
        limpiarLets();
    }
}
