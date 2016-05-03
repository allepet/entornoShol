entorno_shol port para SDL
--------------------------

Esto es un port del entorno gráfico usado para la asignatura Teoría de Lenguajes
de la plataforma Allegro 4 a SDL 2, lo que permite usar dicho entorno en otros
sistemas operativos como OS X, Windows, etc...

El port se ha realizado debido a la antiguedad de Allegro 4, el cual ya ha
deprecado dicha versión y que se encuentra en la versión 5.

Solo ha sido testeado con CLANG 7.3.0 en OS X 10.11.4, pero debería funcionar
sin problema alguno en otros sistemas con un compilador que soporte C++14

Dependencias
------------

	- SDL2 base
	- SDL2_TTF para renderizado de fuentes
	- SDL2_GFX para renderizado de primitivas gráficas

	En linux...
	sudo apt-get install libsdl2-dev libsdl2-gfx-dev libsdl2-ttf-dev

	En OS X con Homebrew...
	brew install sdl2 sdl2_gfx sdl2_ttf

	En Windows...
	Existen binarios y cabeceras precompiladas en la página de SDL y otros
	mirrors

	Una vez hecho esto, SDL2_GFX y SDL2_TTF deberían de ir a la carpeta
	donde se encuentra SDL2, de lo contrario, obtendremos un error del
	tipo 'No se encuentra 'SDL.h'', o al menos en el caso de OS X con brew.

Makefile
--------

	Se ha incluido un makefile con todos los flags necesarios para
	que funcione sin problemas incluyendo las librerias de SDL2, SDL2_TTF
	y SDL2_GFX.

	Posiblemente, las rutas no sean las mismas para ti que en mi caso,
	por tanto, modificar el Makefile con las rutas adecuadas es necesario

Bugs y problemas
---------

	Pues seguro que los hay... así que bug que te encuentres,
	marcalo en Issues y se corregirá , o haz fork y manda pull request!
	
	No dispone de sonido para evitar usar SDL_mixer.

	Es necesario disponer de font.ttf (Subida a este repositorio)
	para renderizar los strings, del contrario, la app no abrirá.
