#include "Def.h"

char* f_finvariable (char* variable){
    char i=0;
    while(*(variable+i)!=' ' && *(variable+i)!='=') //detecta tanto espacios como signos igual.
        i++;
    *(variable+i)='\0';
    return variable+i+1;
}

parametros_t f_inicio (void){
    FILE *conf;
    parametros_t datos_i;
    char cadena[40],*variable,*valor,i,j,aux;
    char variables[2][13]={"nivel_maximo","nivel_minimo"};
    datos_i.configuracion=0;
    datos_i.nivel_maximo=0;
    datos_i.nivel_minimo=0;
    if((conf=fopen("config.conf","rb"))==NULL){
        return datos_i;
    }
    /*no realizo la lectura anticipada ya que en caso de no entrar
    (archivo vacio) la bandera de configuracion se mantiene en 1 y
    no se va a ejecutar el programa*/
    while(!feof(conf)){
        fgets(cadena,40,conf);
        datos_i.configuracion=1;
        variable=cadena;
        if((*variable)!='#' && strlen(variable)>=0){
            valor=f_finvariable(variable);
            for(i=0;i<2;i++){
                if(!strcmp(variable,variables[i])){
                    switch(i){
                        case 0: aux=atoi(valor);//lo guardamos en un auxiliar para llevarlo al formato que usamos.
                                for(j=0;j<aux+1;j++)
                                    datos_i.nivel_maximo=datos_i.nivel_maximo+(1<<j);
                                datos_i.nivel_maximo=~datos_i.nivel_maximo;
                                break;
                        case 1: aux=atoi(valor);
                                for(j=0;j<aux+1;j++)
                                    datos_i.nivel_minimo=datos_i.nivel_minimo+(1<<j);
                                datos_i.nivel_minimo=~datos_i.nivel_minimo;
                                break;
                    }
                }
            }
        }
    }
    return datos_i;
}

estados_t f_espera (parametros_t datos){
    datos.motor=0; //apaga el motor
    datos.nivel=emulacion(); //medicion del nivel
    datos.leds=datos.nivel; //actualizacion de los leds
    muestra(datos); //mostramos los datos para ver como funciona en la emulacion
    if(datos.nivel<datos.nivel_minimo) //verificamos el nivel, como detecta con 0 usamos <
        return espera;
    else
        return carga;
}

estados_t f_carga (parametros_t datos){
    datos.motor=1; //enciende el motor
    datos.nivel=emulacion(); //medicion del nivel
    datos.leds=datos.nivel; //actualizacion de los leds
    muestra(datos); //mostramos los datos para ver como funciona en la emulacion
    if(datos.nivel>datos.nivel_maximo) //verifiamos el nivel, como detecta con 0 usamos >
        return carga;
    else
        return espera;
}

unsigned char emulacion (void){
    char aux,nivel=0;
    int i;
    printf("Ingrese el nivel de agua actual (0-7): ");
    do{
        scanf("%d",&aux);
        if(aux<0 || aux>7)
            printf("\Nivel no valido, ingrese entre 0 y 7: ");
    }while(aux<0 || aux>7);
    for(i=0;i<aux+1;i++)
        nivel=nivel+(1<<i); //lo transformamos al formato que usamos
    nivel=~nivel;
    return nivel;
}

void muestra (parametros_t datos){
    printf("\nNivel: ");
    print_b(datos.nivel);
    printf("\nLeds: ");
    print_b(datos.leds);
    printf("\nMotor: %s\n",(datos.motor==1)?"encendido":"apagado");
}

void print_b (unsigned char byte){
    unsigned char aux;
    int i;
    for(i=7;i>=0;i--){
        aux=byte;
        aux=(aux>>i)&1;
        printf("%d",aux);
    }
}

