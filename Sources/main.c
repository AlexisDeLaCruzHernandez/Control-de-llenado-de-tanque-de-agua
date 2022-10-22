/*
Mi sistema representa el control de llenado de tanque de agua, el mismo censar� 8 niveles de agua donde se podr� configurar
cual es el nivel m�nimo de agua que se puede alcanzar y cu�l ser� el nivel m�ximo para controlar el funcionamiento de la bomba.
Adem�s del control de la bomba el sistema tiene 8 leds los cuales van a indicar en tiempo real cual es el nivel de agua.
Tanto los niveles de agua censados como los 8 leds estar�n contenidos en una variable del tipo char, donde cada uno de los bits
 tendr� el valor de "0" o "1" para indicar si hay agua o no o si el led est� apagado o encendido.
En nuestro sistema vamos a tomar a los niveles con agua con un "0" y sin agua con un "1", los leds estar�n encendidos con "0"
y apagados con "1".
Para emular los niveles de agua vamos a utilizar un scanf donde indicaremos el nivel m�s alto de agua que hay. Si hay agua en
los niveles 0, 1, 2 y 3, en el scanf indicaremos el valor de 3 y pondremos el char de los niveles de agua como 0b11110000
*/

#include "Def.h"

int main()
{
    parametros_t medida;
    estados_t estado=espera;
    estados_t (*pf[])(parametros_t)={f_espera,f_carga};
    medida=f_inicio();
    while(medida.configuracion)
        estado=(*pf[estado])(medida);
    return 0;
}
