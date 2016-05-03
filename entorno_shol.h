/*
 * This file is part of the entorno_shol
 *
 * sholGraphFuncs is a port from original entorno_shol.h and entorno_shol.cpp
 * based on SDL2 , SDL2_TTF and SDL2_GFX
 *
 * Copyright (C) 2016 A. Antunez
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */


#ifndef ENTORNO_H_
#define ENTORNO_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
// -------------------------------------------------------------
// Definición de constantes
// -------------------------------------------------------------

// Definición de constantes para representar los límites del plano
const int ORIGEN_X        = 50;  // Origen de las x
const int ORIGEN_Y        = 50;  // Origen de las y

const int MAX_FILAS        = 500;  // Número máximo de filas del recinto
const int MAX_COLUMNAS     = 400;  // Número máximo de columnas del recinto


// -------------------------------------------------------------
// Definición de tipos
// -------------------------------------------------------------

/**
 *   Permiten definir los distintos tipos de sensores
 *   y de actuadores
 */

enum TipoSensor {Temperatura, Luminosidad, Humo};
enum TipoActuador {Alarma, Luz};

// -------------------------------------------------------------
// Declaración de interfaz (módulos) PÚBLICA
// -------------------------------------------------------------


/**
	POST: Inicia el entorno gráfico	
*/
void inicio ();


/**
	POST: Destruye el entorno gráfico.
*/
void fin();


/**
PRE: El módulo recibe la posición (x,y) en la que imprimir el mensaje y una cadena de caracteres msg
POST: Escribe el mensaje pasado por parámetro en el punto especificado 
*/
void MostrarMensaje (string msg, int x, int y);


/*
 * POST: lleva a cabo una pausa en la ejecución del programa
 * hasta que se pulsa una tecla
 * */
void LeerTecla ();

/**
 * PRE: El módulo recibe la posición (x,y) en la que se colocará el sensor,
 * PRE: x e y deben tener valores incuidos dentro de los límites del recinto,
 * PRE: t representa el tipo de sensor y su valor determinará el color utilizado,
 * PRE: n indica el nombre del sensor y aparecerá junto a la marca
 * POST: Dibuja una marca circular en el punto especificado (x,y) acompañada del nombre del sensor
 * 	Se utilizará para representar un sensor en el plano
 * */
void marca_sensor(int x, int y,  TipoSensor t, string n);

/**
 * PRE: El módulo recibe la posición (x,y) en la que se colocará el sensor,
 * PRE: x e y deben tener valores incuidos dentro de los límites del recinto,
 * PRE: t representa el tipo de sensor y su valor determinará el color utilizado,
 * PRE: v indica el número que aparecerá junto a la marca
 * POST: Coloca, debajo del sensor, el valor que ha detectado
 * */
void valor_sensor(int x, int y,  TipoSensor t, float v);

/**
 * PRE: El módulo recibe la posición (x,y) en la que se colocará el actuador,
 * PRE: x e y deben tener valores incuidos dentro de los límites del recinto,
 * PRE: t representa el tipo de actuador y su valor determinará el color utilizado,
 * PRE: n indica el nombre del actuador y aparecerá junto a la marca
 * POST: Dibuja una marca en el punto (x,y) acompañada del nombre del actuador y de la cadena ON
 * 	Se utilizará para representar un actuador activado
 * */
void activar_actuador(int x, int y, TipoActuador t, string n);

/**
 * PRE: El módulo recibe la posición (x,y) en la que se colocará el actuador,
 * PRE: x e y deben tener valores incuidos dentro de los límites del recinto,
 * PRE: t representa el tipo de actuador y su valor determinará el color utilizado,
 * PRE: n indica el nombre del actuador y aparecerá junto a la marca
 * POST: Dibuja una marca en el punto (x,y) acompañada del nombre del actuador y de la cadena OFF
 * 	Se utilizará para representar un actuador desactivado
 * */
void desactivar_actuador(int x, int y, TipoActuador t, string n);

/**
 * PRE: x1,y1,x2,y2 deben tener valores incuidos dentro del recinto,
 * POST: Dibuja una línea desde las coordenadas (x1,y1) hasta (x2,y2)
 * */
void linea(int x1,int y1,int x2,int y2);


/**
 * PRE: secs >= 0,
 * POST: realiza una pausa de secs segundos
 * */
void pausa(float secs);

#endif

