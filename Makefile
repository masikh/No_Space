# Paths
INCLUDE = -I/opt/X11/include -I/opt/homebrew/include -I/opt/homebrew/include/GL
LIBDIR  = -L/opt/X11/lib -L/opt/homebrew/lib

# Compiler and flags
CC = gcc
COMPILERFLAGS = -Wall -DGL_SILENCE_DEPRECATION
CFLAGS = $(COMPILERFLAGS) $(INCLUDE) `sdl-config --cflags`

# Libraries
LIBRARIES = -lGLU -lglut -lGL -lXmu -lXext -lXi -lm -lX11 -lSDL_mixer

# Output binary name
PROGRAM_NAME = no_space

# Object files
OBJS = main.o texture.o objects.o isocahedron.o light.o scene1.o scene2.o scene3.o scene4.o

# Default rule
all: $(PROGRAM_NAME)

# Linking
$(PROGRAM_NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(OBJS) $(LIBDIR) $(LIBRARIES)
	strip $(PROGRAM_NAME)

# Compile rules
%.o: %.c
	$(CC) -c $< $(CFLAGS)

# Clean rule
clean:
	rm -f *.o $(PROGRAM_NAME)
