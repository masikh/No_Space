#include "scene3.h"

void scene3(double time) {
  float x, y, z;
	int i;

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable (GL_POLYGON_SMOOTH);
	glRotatef (0.4, sinrot_X, cosrot_Y, -sinrot_X);
	glPushMatrix ();

	/* two Isocahedrons */
	glPushMatrix ();
		lighton();
		glEnable (GL_TEXTURE_2D);	// Enable texture mapping.
		glBindTexture (GL_TEXTURE_2D, texture[1]);	// choose the texture to use
		glDisable(GL_FOG);
		glTranslatef (2.5 * -cosrot_3X, 2.5 * -sinrot_3X,	2.5 * -cosrot_3Y);
		drawIsocahedron(0);
		glEnable(GL_FOG);
	glPopMatrix();

	glPushMatrix ();
		lighton();
		glEnable (GL_TEXTURE_2D);	// Enable texture mapping.
		glBindTexture (GL_TEXTURE_2D, texture[1]);	// choose the texture to use
		glDisable(GL_FOG);
		glTranslatef (2.5 * cosrot_3X, 2.5 * sinrot_3X,	2.5 * cosrot_3Y);
		drawIsocahedron(0);
		glEnable(GL_FOG);
		lightoff();
	glPopMatrix();


	glColor3f (0.33F, 0.18F, 1.40F);

	/* A sort of space tree ?? */
	glBegin (GL_POINTS);
	for (i = 1; i <20000; i++) {
		x = Pascal_X[i];
		y = Pascal_Y[i];
		z = Pascal_Z[i];
		glVertex3f (x, y, z);
	}
	glEnd();

	/* The random dots in the middle */
	glBegin (GL_POINTS);
	glDisable(GL_FOG);
	glColor3f (0.0F, 0.40F, 0.10F);
	for (i = 0; i < POINTS; i++) {
		x = Random_X[i] + 0.05 * (float) random() / (float) 0x7fffffff;
		y = Random_Y[i] + 0.05 * (float) random() / (float) 0x7fffffff;
		z = Random_Z[i] + 0.05 * (float) random() / (float) 0x7fffffff;
		glVertex3f (x, y, z);
	}
	glEnd ();

	glDisable(GL_FOG);

	/* A litle redbox in the middle of the scene */
	glColor3f (0.84f, 0.0f, 0.0f);	// Set The Color To Red
	box ();

	/* Solarium background */
	glColor3f (0.3f, 0.3f, 0.3f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture (GL_TEXTURE_2D, texture[2]);	// choose the texture to use
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-10,  10.0, -10.0);
		glTexCoord2f(1.0, 0.0); glVertex3f( 10,  10.0, -10.0);
		glTexCoord2f(1.0, 1.0); glVertex3f( 10, -10.0, -10.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-10, -10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-10,  10.0,  10.0);
		glTexCoord2f(1.0, 0.0); glVertex3f( 10,  10.0,  10.0);
		glTexCoord2f(1.0, 1.0); glVertex3f( 10, -10.0,  10.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-10, -10.0,  10.0);
	glEnd();glBindTexture (GL_TEXTURE_2D, texture[0]);	// choose the texture to use
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-10,  10.0, -10.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(-10, -10.0, -10.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(-10, -10.0,  10.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-10,  10.0,  10.0);
	glEnd();
	glBindTexture (GL_TEXTURE_2D, texture[2]);	// choose the texture to use
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f( 10,  10.0, -10.0);
		glTexCoord2f(1.0, 0.0); glVertex3f( 10,  10.0,  10.0);
		glTexCoord2f(1.0, 1.0); glVertex3f( 10, -10.0,  10.0);
		glTexCoord2f(0.0, 1.0); glVertex3f( 10, -10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-10,  10.0, -10.0);
		glTexCoord2f(1.0, 0.0); glVertex3f( 10,  10.0, -10.0);
		glTexCoord2f(1.0, 1.0); glVertex3f( 10,  10.0,  10.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-10,  10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-10, -10.0, -10.0);
		glTexCoord2f(1.0, 0.0); glVertex3f( 10, -10.0, -10.0);
		glTexCoord2f(1.0, 1.0); glVertex3f( 10, -10.0,  10.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-10, -10.0,  10.0);
	glEnd();
	glPopMatrix();
	glFlush();
  glutSwapBuffers ();
}
