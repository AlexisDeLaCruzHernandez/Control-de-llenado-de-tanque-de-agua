# Control de llenado de tanque de agua
## Esquema del sistema
[![Esquema-TP.png](https://i.postimg.cc/q7MsVMgC/Esquema-TP.png)](https://postimg.cc/BjkL23Tq)
## Memoria descriptiva
Mi sistema representa el control de llenado de tanque de agua, el mismo censará 8 niveles de agua donde se podrá configurar cual es el nivel mínimo de agua que se puede alcanzar y cuál será el nivel máximo para controlar el funcionamiento de la bomba.

Además del control de la bomba el sistema tiene 8 leds los cuales van a indicar en tiempo real cual es el nivel de agua.

Tanto los niveles de agua censados como los 8 leds estarán contenidos en una variable del tipo char, donde cada uno de los bits tendrá el valor de *"0"* o *"1"* para indicar si hay agua o no o si el led está apagado o encendido.

En nuestro sistema vamos a tomar a los niveles con agua con un *"0"* y sin agua con un *"1"*, los leds estarán encendidos con *"0"* y apagados con *"1"*.

>Para emular los niveles de agua vamos a utilizar un scanf donde indicaremos el nivel más alto de agua que hay. Si hay agua en los niveles 0, 1, 2 y 3, en el scanf indicaremos el valor de 3 y pondremos el char de los niveles de agua como *0b11110000* 
## Maquina de estados
[![Maquina-de-estados.png](https://i.postimg.cc/d0pLHqCF/Maquina-de-estados.png)](https://postimg.cc/Mc06XJt3)
- SET: Bandera de fin de inicialización.
- NIVEL: nivel medido por los sensores.
- NIVEL_MINIMO: minimo nivel configurado.
- NIVEL_MAXIMO: maximo nivel configurado.
