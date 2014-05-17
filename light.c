#include "light.h"

void
lighton (void)
{ 
  GLfloat light_ambient0[]  = {  0.1, 0.1,  0.25, 0.0 };
  GLfloat light_ambient1[]  = {  0.0, 0.1,  0.25, 0.0 };
  GLfloat light_diffuse[] 	= {  1.0, 0.0,  0.0,  1.0 };
  GLfloat light_specular[]  = {  0.0, 1.0,  0.0,  1.0 };
  GLfloat light_position0[] = { -0.6, 0.6,  0.0,  0.0 };
  GLfloat light_position1[] = { -0.6,-0.6,  0.0,  0.0 };
  
	glLightfv (GL_LIGHT0, GL_AMBIENT, light_ambient0);
  glLightfv (GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv (GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv (GL_LIGHT0, GL_POSITION, light_position0);
  glLightfv (GL_LIGHT1, GL_AMBIENT, light_ambient1);
  glLightfv (GL_LIGHT1, GL_DIFFUSE, light_diffuse);
  glLightfv (GL_LIGHT1, GL_SPECULAR, light_specular);
  glLightfv (GL_LIGHT1, GL_POSITION, light_position1);
  
	glEnable (GL_LIGHTING);
  glEnable (GL_LIGHT0);
  glEnable (GL_LIGHT1);
  glEnable (GL_DEPTH_TEST);
	
	GLfloat surface_ambient[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat surface_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat surface_diffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat shininess = 90.0;
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, surface_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, surface_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, surface_diffuse);
	
	GLfloat fogColor[4] = {0.8, 0.8, 0.8, 1.0};
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.3);
	glEnable(GL_FOG);
}

void
lightoff (void)
{
  glDisable (GL_LIGHTING);
}
