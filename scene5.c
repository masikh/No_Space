#include "main.h"


void scene5() {
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glPushMatrix();
		glPushMatrix();
			background();
		glPopMatrix();
		glPushMatrix();
			glBindTexture (GL_TEXTURE_2D, texture[6]);
			glColor4f(0.3f,0.3f,0.3f,0.5f);			// Full Brightness, 50% Alpha ( NEW )
			glBlendFunc(GL_SRC_ALPHA,GL_ONE);		// Blending Function For Translucency Based On Source Alpha Value ( NEW )
			glEnable(GL_BLEND);		// Turn Blending On
			glDisable(GL_DEPTH_TEST);	// Turn Depth Testing Off
			glTranslatef(-3.0, -2.0 + cosrot_3X, sinrot_3X * 5.0);
			glRotatef (fmod(20 * dif,360), 1.0, 1.0, 0.0);
			CubeMatrix();
			glDisable(GL_BLEND);
			glEnable(GL_DEPTH_TEST);
		glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
