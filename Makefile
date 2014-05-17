INCLUDE = -I/sw/include/GL -I/sw/include
LIBDIR  = -L. -L/usr/X11R6/lib -L/usr/lib -L/usr/X11R6/lib/modules/extensions/
COMPILERFLAGS = -Wall
CC = gcc
CFLAGS = $(COMPILERFLAGS) $(INCLUDE) `sdl-config --cflags`
LIBRARIES = -lGLU -lglut -lGL -lXmu -lXext -lXi -lm -lX11 -lSDL_mixer
PROGRAM-NAME = no_space 

all: $(PROGRAM-NAME)

$(PROGRAM-NAME) : main.o texture.o objects.o isocahedron.o light.o scene1.o scene2.o scene3.o scene4.o
	$(CC) $(CFLAGS) -o $(PROGRAM-NAME) $(LIBDIR) $(LIBRARIES) main.o texture.o objects.o isocahedron.o light.o scene1.o scene2.o scene3.o scene4.o
	strip $(PROGRAM-NAME)

main.o : main.c
	$(CC) -c main.c $(CFLAGS)

texture.o : texture.c
	$(CC) -c texture.c $(CFLAGS)

objects.o : objects.c
	$(CC) -c objects.c $(CFLAGS)

isocahedron.o : isocahedron.c
	$(CC) -c isocahedron.c $(CFLAGS)

light.o : light.c
	$(CC) -c light.c $(CFLAGS)

scene1.o : scene1.c
	$(CC) -c scene1.c $(CFLAGS)

scene2.o : scene2.c
	$(CC) -c scene2.c $(CFLAGS)

scene3.o : scene3.c
	$(CC) -c scene3.c $(CFLAGS)

scene4.o : scene4.c
	$(CC) -c scene4.c $(CFLAGS)
clean:
	rm -f *.o


