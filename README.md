PAV - P5: síntesis musical polifónica
=====================================

Obtenga su copia del repositorio de la práctica accediendo a [Práctica 5](https://github.com/albino-pav/P5) 
y pulsando sobre el botón `Fork` situado en la esquina superior derecha. A continuación, siga las
instrucciones de la [Práctica 2](https://github.com/albino-pav/P2) para crear una rama con el apellido de
los integrantes del grupo de prácticas, dar de alta al resto de integrantes como colaboradores del proyecto
y crear la copias locales del repositorio.

Como entrega deberá realizar un *pull request* con el contenido de su copia del repositorio. Recuerde que
los ficheros entregados deberán estar en condiciones de ser ejecutados con sólo ejecutar:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.sh
  make release
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

A modo de memoria de la práctica, complete, en este mismo documento y usando el formato *markdown*, los
ejercicios indicados.

Ejercicios.
-----------

### Envolvente ADSR.

Tomando como modelo un instrumento sencillo (puede usar el InstrumentDumb), genere cuatro instrumentos que
permitan visualizar el funcionamiento de la curva ADSR.

* Un instrumento con una envolvente ADSR genérica, para el que se aprecie con claridad cada uno de sus
  parámetros: ataque (A), caída (D), mantenimiento (S) y liberación (R).
  ![](https://github.com/davilin98/P5/blob/Guardia-Linde/imagenes/gen.JPG)
  > Los parametros que hemos usado son: A=0.1, D=0.2, S=0.4 y R=0.2. Primeramente nos gustaría comentar que nos hemos creado un sco que solo tenga 2 notas, para ver mejor los parametros. principalmente se observan a la perfección los parametros nombrados, observando un tiempo de ataque de 0.1, un tiempo de caída de 0.2, se mantiene durante 0.4 y finalmente se obserba un tiempo de liberación de 0.2 segundos, aunque no se acaba del todo ya que empiza la siguiente nota.
* Un instrumento *percusivo*, como una guitarra o un piano, en el que el sonido tenga un ataque rápido, no haya mantenimiemto y el sonido se apague lentamente.
  > Principalmente la única diferencia que existirá entre los dos casos sera el release donde en uno sera un release grande, (hasta que se acabe la nota), y en el otro tendremos un release muy pequeño (haciendo que la nota se acabe).
>Para ello hemos usado como parametros A=0.2,D=0.4, S=0
  - Para un instrumento de este tipo, tenemos dos situaciones posibles:  
    * El intérprete mantiene la nota *pulsada* hasta su completa extinción.
    ![](https://github.com/davilin98/P5/blob/Guardia-Linde/imagenes/perc.JPG)
    >Para este caso hemos usado R=0.5.
    * El intérprete da por finalizada la nota antes de su completa extinción, iniciándose una disminución abrupta del sonido hasta su finalización.
    ![](https://github.com/davilin98/P5/blob/Guardia-Linde/imagenes/perc1.JPG)
    >En este caso R=0.1. Se puede observar que en este caso no se llega al final de la nota sino que se observa un tiempo de liberación pequeño haciendo que la note se acabe bruscamente.
  - Debera representar en esta memoria **ambos** posibles finales de la nota.
* Un instrumento *plano*, como los de cuerdas frotadas (violines y semejantes) o algunos de viento. En
![](https://github.com/davilin98/P5/blob/Guardia-Linde/imagenes/plana.JPG)
> Aqui observamos que la respuesta es del todo plana, para conseguirlo hemos utilizado un tiempo de ataque muy pequeño (A=0.02), una tiempo de caída nulo (D=0), un sustain grande (S=0.5, hemos usado 0.5 para que se visualizara como se acabava la nota) y un tiempo de liberación muy pequeño (de nuevo R=0.02).
  ellos, el ataque es relativamente rápido hasta alcanzar el nivel de mantenimiento (sin sobrecarga), y la
  liberación también es bastante rápida.

Para los cuatro casos, deberá incluir una gráfica en la que se visualice claramente la curva ADSR. Deberá
añadir la información necesaria para su correcta interpretación, aunque esa información puede reducirse a
colocar etiquetas y títulos adecuados en la propia gráfica (se valorará positivamente esta alternativa).

### Instrumentos Dumb y Seno.

Implemente el instrumento `Seno` tomando como modelo el `InstrumentDumb`. La señal **deberá** formarse
mediante búsqueda de los valores en una tabla.

- Incluya, a continuación, el código del fichero `seno.cpp` con los métodos de la clase Seno.
- Explique qué método se ha seguido para asignar un valor a la señal a partir de los contenidos en la tabla,
  e incluya una gráfica en la que se vean claramente (use pelotitas en lugar de líneas) los valores de la
  tabla y los de la señal generada.
- Si ha implementado la síntesis por tabla almacenada en fichero externo, incluya a continuación el código
  del método `command()`.

### Efectos sonoros.

- Incluya dos gráficas en las que se vean, claramente, el efecto del trémolo y el vibrato sobre una señal
  sinusoidal. Deberá explicar detalladamente cómo se manifiestan los parámetros del efecto (frecuencia e
  índice de modulación) en la señal generada (se valorará que la explicación esté contenida en las propias
  gráficas, sin necesidad de *literatura*).
  
  ![](https://github.com/davilin98/P5/blob/Guardia-Linde/imagenes/tremolo.PNG)

> En el tremolo podemos observar una fluctuación de la amplitud en la primera envolvente, mientras que la segunda es la original. 

![](https://github.com/davilin98/P5/blob/Guardia-Linde/imagenes/vibrato.PNG)
![](https://github.com/davilin98/P5/blob/Guardia-Linde/imagenes/vibrato1.PNG)  
 
> La primera imagen es aplicando vibrato (I = 24; fm = 2000) y la segunda sin vibrato. 
>En el vibrato podemos observar que al realizar una fluctuación de la frecuencia, la cual se ve reflectida en el seno en el eje temporal. También podemos observar en el espectrograma que aparecen frecuencias nuevas.  
 
- Si ha generado algún efecto por su cuenta, explique en qué consiste, cómo lo ha implementado y qué
  resultado ha producido. Incluya, en el directorio `work/ejemplos`, los ficheros necesarios para apreciar
  el efecto, e indique, a continuación, la orden necesaria para generar los ficheros de audio usando el
  programa `synth`.

### Síntesis FM.

Construya un instrumento de síntesis FM, según las explicaciones contenidas en el enunciado y el artículo
de [John M. Chowning](https://ccrma.stanford.edu/sites/default/files/user/jc/fm_synthesispaper-2.pdf). El
instrumento usará como parámetros **básicos** los números `N1` y `N2`, y el índice de modulación `I`, que
deberá venir expresado en semitonos.

- Use el instrumento para generar un vibrato de *parámetros razonables* e incluya una gráfica en la que se
  vea, claramente, la correspondencia entre los valores `N1`, `N2` e `I` con la señal obtenida.
  >Para explicar el efecto de N1,N2 e I, hemos creado 3 señales con distintas N1,N2 e I para así poder ver visualmente los efectos que se produce. 
  > En primer lugar nos encontramos una gráfica con N1 = 100, N2= 10, I = 10. A partir de la equivalencia que sabemos fc=fm*N1/N2 
podemos saber que la frecuencia de la portadora será 10 veces mayor a la de la moduladora, también, al tener I = 10, observaremos un gran efecto de modulación. 

![](https://github.com/davilin98/P5/blob/Guardia-Linde/imagenes/fm(N1%3D100%2CN2%3D10%2CI%3D10).PNG)
 
> En este segundo ejemplo, hemos usado los mismos parámetros de N1 y N2, lo que hemos cambiado es la profundidad del vibrato, I=1.
Se puede observar que el efecto de la moduladora es mucho menor. 

![](https://github.com/davilin98/P5/blob/Guardia-Linde/imagenes/fm(N1%3D100%2CN2%3D10%2CI%3D5).PNG)

> Finalmente, para observar el comportamiento de N1 y N2, hemos creado una señal con N1 = 50 y N2 = 10, esto indica que fc = 5fm por lo tanto, también se puede observar que fc genera 5 ciclos de señal por un ciclo que realiza fm. I = 10. En esta, a diferencia de la primera, se puede observar que produce un efecto distinto cada 5 ciclos de fc.  

![](https://github.com/davilin98/P5/blob/Guardia-Linde/imagenes/fm(N1%3D50%2CN2%3D10%2CI%3D10).PNG)

- Use el instrumento para generar un sonido tipo clarinete y otro tipo campana. Tome los parámetros del
  sonido (N1, N2 e I) y de la envolvente ADSR del citado artículo. Con estos sonidos, genere sendas escalas
  diatónicas (fichero `doremi.sco`) y ponga el resultado en los ficheros `work/doremi/clarinete.wav` y
  `work/doremi/campana.work`.
  
  > Para crear el clarinete hemos usado estos parámetros : ADSR_A=0.1; ADSR_D=0; ADSR_S=0.3; ADSR_R=0.1; N1=900; N2=600; I=2;
  > Para crear la campana hemos usado estos parámetros : ADSR_A=0.0001; ADSR_D=0.01; ADSR_S=0.01; ADSR_R=0.05; N1=200; N2=280; I=10;
  
  * También puede colgar en el directorio work/doremi otras escalas usando sonidos *interesantes*. Por
    ejemplo, violines, pianos, percusiones, espadas láser de la
	[Guerra de las Galaxias](https://www.starwars.com/), etc.

### Orquestación usando el programa synth.

Use el programa `synth` para generar canciones a partir de su partitura MIDI. Como mínimo, deberá incluir la
*orquestación* de la canción *You've got a friend in me* (fichero `ToyStory_A_Friend_in_me.sco`) del genial
[Randy Newman](https://open.spotify.com/artist/3HQyFCFFfJO3KKBlUfZsyW/about).

- En este triste arreglo, la pista 1 corresponde al instrumento solista (puede ser un piano, flautas,
  violines, etc.), y la 2 al bajo (bajo eléctrico, contrabajo, tuba, etc.).
- Coloque el resultado, junto con los ficheros necesarios para generarlo, en el directorio `work/music`.
- Indique, a continuación, la orden necesaria para generar la señal (suponiendo que todos los archivos
  necesarios están en directorio indicado).
> Nos colocamos en P5/work .

> synth orchest/toyStory.orc ../samples/ToyStory_A_Friend_in_me.sco music/ToyStory.wav

También puede orquestar otros temas más complejos, como la banda sonora de *Hawaii5-0* o el villacinco de
John Lennon *Happy Xmas (War Is Over)* (fichero `The_Christmas_Song_Lennon.sco`), o cualquier otra canción
de su agrado o composición. Se valorará la riqueza instrumental, su modelado y el resultado final.
- Coloque los ficheros generados, junto a sus ficheros `score`, `instruments` y `efffects`, en el directorio
  `work/music`.
- Indique, a continuación, la orden necesaria para generar cada una de las señales usando los distintos
  ficheros.
> Hemos realizado la canción Clair de lune del autor, Claude Debussy, es una versión acelerada, es el único .mid que hemos encotrado fácilmente. Hemos pasado el .mid por el programa midi2scores y a partir de ahí hemos creado los 2 instrumentos que nos pedía aunque la canción es únicamente a piano. 

> synth orchest/clair_de_lune.orc ../samples/clair_de_lune.sco music/clair_de_lune.wav
