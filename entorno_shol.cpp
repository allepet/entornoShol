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

#include "entorno_shol.h"

// -------------------------------------------------------------
// Declaración de módulos PRIVADOS
// -------------------------------------------------------------
//Transforma un número real en un string
string toString(float numero);


// -------------------------------------------------------------
// Definición de módulos PRIVADOS
// -------------------------------------------------------------
string toString(float numero) {
        char *cstr = (char*) malloc(0xFF);
        cstr[sprintf(cstr, "%6g",numero)]='\0';
        return cstr;
}

// ——
// VARIABLES SDL
// —

SDL_Window *wnd = nullptr;
SDL_Renderer *renderer = nullptr;
TTF_Font *fnt_pt = nullptr;

void renderString(const char * str, int x, int y, int r, int g, int b){
        SDL_Color col;
        y-=3;
        col.a = 0xFF;
        col.r = r;
        col.g = g;
        col.b = b;
        SDL_Surface *txt_srfc = TTF_RenderText_Blended(fnt_pt, str, col);
        SDL_Rect dst_rect = txt_srfc->clip_rect;
        dst_rect.x = x;
        dst_rect.y = y;
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, txt_srfc);
        SDL_RenderCopy(renderer, texture, &txt_srfc->clip_rect, &dst_rect);
        SDL_free(txt_srfc);
}

// -------------------------------------------------------------
// Definición de la interfaz PÚBLICA
// -------------------------------------------------------------

void inicio(){
        if (SDL_Init(SDL_INIT_EVERYTHING) || TTF_Init())
            exit(1);
        wnd = SDL_CreateWindow("SHOL GUI", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,800, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(wnd,-1,SDL_RENDERER_SOFTWARE);
        fnt_pt = TTF_OpenFont("font.ttf", 12);
        if (fnt_pt == NULL){
            printf("Font (font.ttf) not found! Exiting...\n");
            exit(1);
        }
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderClear(renderer);
        int fila,columna;
        fila = 60;
        columna = 560;
        renderString("Smart Home", columna, fila, 0xFF,0xFF,0xFF);
        fila = 80;
        renderString("Proyecto TL", columna, fila, 0xFF,0xFF,0xFF);
        fila = 100;
        renderString("Curso 2015/2016", columna, fila, 0xFF,0xFF,0xFF);
        renderString("Simulador de Smart Home - Plano de la casa", 50, 10, 0xFF,0xFF,0xFF);
        SDL_Rect *rect = new SDL_Rect();
        rect->x = ORIGEN_X-5;
        rect->y = ORIGEN_Y-5;
        rect->w = 455;
        rect->h = 555;
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        SDL_RenderFillRect(renderer, rect);
        fila = 180; columna = 560;
        renderString("Sensor de temperatura", columna+20,fila , 0,0xFF,0);
        ellipseRGBA(renderer, columna, fila, 6,6,0,0xFF,0,0xFF);
        fila = 200; columna = 560;
        renderString("Sensor de luminosidad",columna+20,fila,0xFF,0xFF,0xFF);
        ellipseColor(renderer, columna, fila, 6,6, 0xFFFFFFFF);
        fila = 220; columna = 560;
        renderString("Sensor de humo",columna+20,fila,0x00,0x00,0xFF);
        ellipseRGBA(renderer, columna, fila, 6,6, 0x00,0x00,0xFF,0xFF);
        fila = 250; columna = 560;
        renderString("Alarma",columna+20,fila,0xFF,0x00,0x00);
        ellipseColor(renderer, columna, fila, 6,6, 0xFF0000FF);
        fila = 270; columna = 560;
        renderString("Luz",columna+20,fila,0xFF,0xB4,0x00);
        ellipseRGBA(renderer, columna, fila, 6,6, 0xFF,0xB4,0x00,0xFF);
        SDL_RenderPresent(renderer);	
}


void fin(){
        SDL_free(wnd);
        SDL_free(renderer);
        SDL_free(fnt_pt);
}


void MostrarMensaje (string msg, int fila, int columna) {
    SDL_RenderPresent(renderer);
    renderString(msg.c_str(),columna+2+ORIGEN_Y,fila +ORIGEN_X ,0x00,0x00,0x00);
    SDL_RenderPresent(renderer);
}

void LeerTecla () {
    SDL_Event e;    //The SDL event that we will poll to get events.
    bool ok = true;
    while (SDL_WaitEvent(&e)&&ok)   //Poll our SDL key event for any keystrokes.
    {
        switch(e.type){
            case SDL_KEYDOWN:
                ok=false;
                break;
        }
    }

}


void marca_sensor(int x, int y, TipoSensor sensor, string nombre){
        SDL_RenderPresent(renderer);
        std::swap(x,y);
        switch (sensor){
        case Temperatura:
            filledCircleRGBA(renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6,  0,0xFF,0,0xFF);
            renderString(nombre.c_str(), x+ORIGEN_X-3, y+ORIGEN_Y-18,0,0xFF,0);
            break;
        case Luminosidad:
            filledCircleRGBA(renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6,0xFF,0xFF,0xFF,0xFF);
            renderString(nombre.c_str(), x+ORIGEN_X-3, y+ORIGEN_Y-18, 0xFF,0xFF,0xFF);
            break;
        case Humo:
            filledCircleRGBA(renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6,  0,0,0xFF,0xFF);
            renderString(nombre.c_str(), x+ORIGEN_X-3, y+ORIGEN_Y-18,0,0,0xFF);
            break;
        };
        SDL_RenderPresent(renderer);
}

void valor_sensor(int x, int y, TipoSensor sensor, float valor){
        std::swap( x,y);
        SDL_Rect rect;
        rect.x = x +ORIGEN_X-6;
        rect.y = y+ORIGEN_Y+10;
        rect.w = 50;
        rect.h = 14;
        SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
        switch (sensor){
        case Temperatura:
            circleRGBA( renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6, 0,255,0,255);
            renderString(toString(valor).c_str(), x +ORIGEN_X-6 ,y+ORIGEN_Y+10,0,255,0);
            break;
        case Luminosidad:
            circleRGBA( renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6, 0xFF,0xFF,0xFF,0xFF);
            renderString(toString(valor).c_str(), x +ORIGEN_X-6 ,y+ORIGEN_Y+10,0xFF,0xFF,0xFF);
            break;
        case Humo:
            circleRGBA( renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6, 0x00,0x00,0xFF,0xFF);
            renderString(toString(valor).c_str(), x +ORIGEN_X-6 ,y+ORIGEN_Y+10,0x00,0x00,0xFF);
            break;
        };
}


void activar_actuador(int x, int y, TipoActuador actuador, string nombre){
        std::swap( x,y);
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = 100;
        rect.h = 100;
        SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
        switch (actuador){
        case Alarma:
            filledCircleRGBA( renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6, 0xFF,0x00,0x00,0xFF);
            renderString(nombre.c_str(), x +ORIGEN_X-3 ,y+ORIGEN_Y-18, 0xFF,0x00,0x00);
            renderString("ON", x +ORIGEN_X-6 ,y+ORIGEN_Y+10, 0xFF,0x00,0x00);
            break;
        case Luz:
            filledCircleRGBA( renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6, 0xFF,0xB4,0x00,0xFF);
            renderString(nombre.c_str(), x +ORIGEN_X-3 ,y+ORIGEN_Y-18,0xFF,0xB4,0x00);
            renderString("ON", x +ORIGEN_X-6 ,y+ORIGEN_Y+10,0xFF,0xB4,0x00);
            break;
        };
        SDL_RenderPresent(renderer);
}

void desactivar_actuador(int x, int y, TipoActuador actuador, string nombre){
        std::swap( x,y);
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = 100;
        rect.h = 100;
        SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
        switch (actuador){
        case Alarma:
            filledCircleRGBA( renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6, 0xFF,0xFF,0xFF,0xFF);
            circleRGBA(renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6 , 0xFF,0x00,0x00,0xFF);
            renderString(nombre.c_str(), x +ORIGEN_X-3 ,y+ORIGEN_Y-18, 0xFF,0x00,0x00);
            renderString("OFF", x +ORIGEN_X-6 ,y+ORIGEN_Y+10, 0xFF,0x00,0x00);
            break;
        case Luz:
            filledCircleRGBA( renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6, 0xFF,0xFF,0xFF,0xFF);
            circleRGBA(renderer, ORIGEN_X + x,   ORIGEN_Y + y, 6 , 0xFF,0xB4,0x00,0xFF);
            renderString(nombre.c_str(), x +ORIGEN_X-3 ,y+ORIGEN_Y-18,0xFF,0xB4,0x00);
            renderString("OFF", x +ORIGEN_X-6 ,y+ORIGEN_Y+10,0xFF,0xB4,0x00);
            break;
        };
        SDL_RenderPresent(renderer);
}


void linea(int x1,int y1,int x2,int y2){
       SDL_RenderPresent(renderer);
       std::swap(x1,y1);
       std::swap(x2,y2);
       lineRGBA(renderer, ORIGEN_X+x1,ORIGEN_Y+y1,ORIGEN_X+x2,ORIGEN_Y+y2, 0x00,0x00,0x00,0xFF);
       SDL_RenderPresent(renderer);
}


void pausa(float secs){
        secs*=1000;
        SDL_Event e;
        while (secs--){
            SDL_PollEvent(&e);
            if (e.type == SDL_QUIT) exit(0);
            SDL_Delay(1);
        }
}



