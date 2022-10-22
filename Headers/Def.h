#ifndef DEF_H
#define DEF_H
#include <stdio.h>
#include <string.h>

typedef enum{
    espera=0,
    carga=1
}estados_t;

typedef struct{
    unsigned char nivel_minimo;
    unsigned char nivel_maximo;
    unsigned char nivel;
    unsigned char leds;
    unsigned char motor;
    unsigned char configuracion;
}parametros_t;

char* f_finvariable (char*);
parametros_t f_inicio (void);
estados_t f_espera (parametros_t);
estados_t f_carga (parametros_t);
unsigned char emulacion (void); //Para emular los sensores
void muestra (parametros_t); //para mostrar los parametros
void print_b (unsigned char); //para imprimir en binario
#endif
