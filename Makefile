
CXX=g++ -std=c++14

INCLUDE=-I/usr/local/Cellar/sdl2/2.0.4/include -I/usr/local/Cellar/sdl2_ttf/2.0.14/include -I/usr/local/Cellar/sdl2_gfx/1.0.1/include

LDD= -L/usr/local/Cellar/sdl2/2.0.4/lib -lSDL2 -L/usr/local/Cellar/sdl2_ttf/2.0.14/lib -lSDL2_ttf -L/usr/local/Cellar/sdl2_gfx/1.0.1/lib -lSDL2_gfx

OBJS=entorno_shol prueba1

all: $(OBJS) app

$(OBJS):
	$(CXX) $(INCLUDE) -c $@.cpp -obuild/$@.o

app:
	$(CXX) $(INCLUDE) $(LDD) build/*.o -oprueba
