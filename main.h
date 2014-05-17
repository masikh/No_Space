// main.h header file

/* standard C libs */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

/* OpenGL and SDL libs */
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
//#include <SDL/SDL.h>
//#include <SDL_mixer/SDL_mixer.h>

/* My own libs */
#include "texture.h"
#include "objects.h"
#include "isocahedron.h"
#include "light.h"

#define TITLE "<- Random -> [esc]: quits [a/z]: zoom"
#define PI 3.1415926535897

GLuint isocahedron;
//GLuint pascal;

size_t strlen(const char *s);
char *strcpy(char *dest, const char *src);

//Mix_Music *soundtrack;		/* Set up buffer */

double dif; // difference between now and begin

int winIdMain;

float floatsin[7200];
float floatcos[7200];
float floatsin3[7200];
float floatcos3[7200];
float sinrot_X, sinrot_Y, cosrot_X, cosrot_Y, sinrot_3X, sinrot_3Y, cosrot_3X, cosrot_3Y;

void LoadGLTextures (void); // prototype
void scene1();
void scene2();
void scene3(double dif);
void scene4();
