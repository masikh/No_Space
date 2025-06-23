// objects.h header file
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void Random_XYZ(float *Random_X, float *Random_Y, float *Random_Z);
void Pascal_XYZ(float *Pascal_X, float *Pascal_Y, float *Pascal_Z);
void wobbly(float* x, float* y, float* z, int i, float *Random_X, float *Random_Y, float *Random_Z);
void DrawPascal(float *Pascal_X, float *Pascal_Y, float *Pascal_Z, float color, float scenesize);
void sphere(float scale);
void drawsphere(float scale);
