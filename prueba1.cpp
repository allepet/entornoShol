#include "entorno_shol.h"

int main(){
  inicio();

  linea(0,0,0,400);  
  linea(0,400,350,400);
  linea(350,400,350,350);
  linea(350,350,500,350);
  linea(500,350,500,0);
  linea(500,0,0,0);   
  

  marca_sensor(100,100,Temperatura,"A"); pausa (1);   
  marca_sensor(100,180,Humo,"H");pausa (1);  
  desactivar_actuador(250,100,Luz, "L_1");pausa (1);
  desactivar_actuador(250,200,Luz, "L_2");pausa (1);
  desactivar_actuador(100,320,Alarma, "B");pausa (1);

  valor_sensor(100,100,Temperatura,25.5);
  valor_sensor(100,180,Humo,0.3);
  pausa (1);

  MostrarMensaje ("SIMULACION", 50,100);
  LeerTecla();
  MostrarMensaje ("1", 0,0);
  activar_actuador(250,100,Luz, "L_1");
  
  activar_actuador(100,320,Alarma, "B");
  pausa (2);
  desactivar_actuador(100,320,Alarma, "B");
  pausa (5);
 
  activar_actuador(100,320,Alarma, "B");
  pausa (2);
  desactivar_actuador(100,320,Alarma, "B");
  pausa (5);

  activar_actuador(100,320,Alarma, "B");
  pausa (2);
  desactivar_actuador(100,320,Alarma, "B");
  pausa (5);

  activar_actuador(250,200,Luz, "L_2");

  pausa (1);
  desactivar_actuador(250,200,Luz, "L_2");

  fin();
  return 0;
}
