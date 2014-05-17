#include "main.h"

void eof() {
	glBindTexture (GL_TEXTURE_2D, texture[5]);	// choose the texture to use

	// draw a cubic
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.1 + sinrot_X,  1.1 + sinrot_3X, -1.1);
		glTexCoord2f(1.0, 0.0); glVertex3f( 1.1 + sinrot_X,  1.1 + sinrot_3X, -1.1);
		glTexCoord2f(1.0, 1.0); glVertex3f( 1.1 + sinrot_X, -1.1 + sinrot_3X, -1.1);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1.1 + sinrot_X, -1.1 + sinrot_3X, -1.1);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1.1 + sinrot_X,  1.1 + sinrot_3X,  1.1);
		glTexCoord2f(0.0, 0.0); glVertex3f( 1.1 + sinrot_X,  1.1 + sinrot_3X,  1.1);
		glTexCoord2f(0.0, 1.0); glVertex3f( 1.1 + sinrot_X, -1.1 + sinrot_3X,  1.1);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.1 + sinrot_X, -1.1 + sinrot_3X,  1.1);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.1 + sinrot_X,  1.1 + sinrot_3X, -1.1);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1.1 + sinrot_X, -1.1 + sinrot_3X, -1.1);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.1 + sinrot_X, -1.1 + sinrot_3X,  1.1);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1.1 + sinrot_X,  1.1 + sinrot_3X,  1.1);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f( 1.1 + sinrot_X,  1.1 + sinrot_3X, -1.1);
		glTexCoord2f(1.0, 0.0); glVertex3f( 1.1 + sinrot_X,  1.1 + sinrot_3X,  1.1);
		glTexCoord2f(1.0, 1.0); glVertex3f( 1.1 + sinrot_X, -1.1 + sinrot_3X,  1.1);
		glTexCoord2f(0.0, 1.0); glVertex3f( 1.1 + sinrot_X, -1.1 + sinrot_3X, -1.1);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1.1 + sinrot_X,  1.1 + sinrot_3X, -1.1);
		glTexCoord2f(0.0, 0.0); glVertex3f( 1.1 + sinrot_X,  1.1 + sinrot_3X, -1.1);
		glTexCoord2f(0.0, 1.0); glVertex3f( 1.1 + sinrot_X,  1.1 + sinrot_3X,  1.1);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.1 + sinrot_X,  1.1 + sinrot_3X,  1.1);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.1 + sinrot_X, -1.1 + sinrot_3X, -1.1);
		glTexCoord2f(1.0, 0.0); glVertex3f( 1.1 + sinrot_X, -1.1 + sinrot_3X, -1.1);
		glTexCoord2f(1.0, 1.0); glVertex3f( 1.1 + sinrot_X, -1.1 + sinrot_3X,  1.1);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1.1 + sinrot_X, -1.1 + sinrot_3X,  1.1);
	glEnd();
}

void
scene4() {
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable (GL_POLYGON_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	GLfloat light_ambient[]  = {  1.0, 1.0,  1.0, 0.0 };
	GLfloat light_diffuse[] 	= {  1.0, 1.0, 1.0,  1.0 };
	GLfloat light_specular[]  = {  1.0, 1.0,  1.0,  1.0 };
	GLfloat light_position[] = { 0.0, 0.0,  10.0,  0.0 };
	glLightfv (GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv (GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv (GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv (GL_LIGHT0, GL_POSITION, light_position);
	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glEnable (GL_DEPTH_TEST);

	glPushMatrix();
		glPushMatrix();
			glRotatef(fmod(dif * 20, 360), sinrot_X, cosrot_Y, -sinrot_X);
			eof();
		glPopMatrix();
	glPopMatrix();
 	glutSwapBuffers ();
}
