#include "main.h"

void background() {
	glBindTexture( GL_TEXTURE_2D, texture[4] );
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBegin(GL_QUADS);
		glColor4f(1.0f,1.0f,1.0f,0.1f);
		glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -8.0f + sinrot_3X * 0.2,  -6.4f, -5.0f + sinrot_X);
		glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  8.0f + sinrot_3X * 0.2,  -6.4f, -5.0f + sinrot_X);
		glTexCoord2f( 1.0f, 0.5f ); glVertex3f(  8.0f + cosrot_3X * 0.2, -0.2f, -5.0f + sinrot_X);
		glTexCoord2f( 0.0f, 0.5f ); glVertex3f( -8.0f + sinrot_X * 0.2, -0.2f, -5.0f + sinrot_X);
		glTexCoord2f( 0.0f, 0.5f ); glVertex3f( -8.0f + sinrot_X * 0.2,  -0.2f, -5.0f + sinrot_X);
		glTexCoord2f( 1.0f, 0.5f ); glVertex3f(  8.0f + cosrot_3X * 0.2,  -0.2f, -5.0f + sinrot_X);
		glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  8.0f + sinrot_3X * 0.2,  6.7f, -5.0f + sinrot_X);
		glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -8.0f + sinrot_3X * 0.2,  6.7f, -5.0f + sinrot_X);
	glEnd( );
}

void singlecube() {
	glBegin(GL_QUADS);
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, -0.1f, -0.1f);	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.1f, -0.1f, -0.1f);	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.1f, -0.1f,  0.1f);	// Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -0.1f,  0.1f);	// Bottom Right Of The Texture and Quad
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -0.1f,  0.1f);	// Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.1f, -0.1f,  0.1f);	// Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.1f,  0.1f,  0.1f);	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f,  0.1f,  0.1f);	// Top Left Of The Texture and Quad
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -0.1f, -0.1f);	// Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f,  0.1f, -0.1f);	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.1f,  0.1f, -0.1f);	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.1f, -0.1f, -0.1f);	// Bottom Left Of The Texture and Quad
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.1f, -0.1f, -0.1f);	// Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.1f,  0.1f, -0.1f);	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.1f,  0.1f,  0.1f);	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.1f, -0.1f,  0.1f);	// Bottom Left Of The Texture and Quad
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -0.1f, -0.1f);	// Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -0.1f,  0.1f);	// Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f,  0.1f,  0.1f);	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f,  0.1f, -0.1f);	// Top Left Of The Texture and Quad
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f,  0.1f, -0.1f);	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f,  0.1f,  0.1f);	// Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.1f,  0.1f,  0.1f);	// Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.1f,  0.1f, -0.1f);	// Top Right Of The Texture and Quad
	glEnd();								// Done Drawing Quad
}


void CubeMatrix() {
	int PlaneX, PlaneY, PlaneZ;
	int depth = 5;

	for (PlaneX = 0; PlaneX < depth; PlaneX++) {
		for (PlaneY = 0; PlaneY < depth; PlaneY++) {
			for (PlaneZ = 0; PlaneZ < depth; PlaneZ++) {
				singlecube();
				glTranslatef(0.0,0.0,0.3);
			}
			glTranslatef(0.0,0.0,-depth * 0.3);
			glTranslatef(0.0,0.3,0.0);
		}
		glTranslatef(0.0, -depth * 0.3, 0.0);
		glTranslatef(0.3, 0.0, 0.0);
	}
}

void scene1() {
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
