#include "scene2.h"
#include "main.h"
#include <math.h>
static int const speed=4; // The descent speed through the tunnel

/* X and Y values on a normalized circle (angle += PI/6 for each new pair) */
static GLfloat vdata[12][2] = {
	{ 1.0f, 0.0f},{ 0.87f, 0.50f},{ 0.50f, 0.87f},
	{ 0.0f, 1.0f},{-0.50f, 0.87f},{-0.87f, 0.50f},
	{-1.0f, 0.0f},{-0.87f,-0.50f},{-0.50f,-0.87f},
	{ 0.0f,-1.0f},{ 0.50f,-0.87f},{ 0.87f,-0.50f}
};

void tunnel() {
	int i, j, tunnellength = 30; // Just some Counters (j and tunnellength are related)
	float X[12], Y[12], Z0 , Z1; // The x, y, and z values of each poligon
	/* If j == tunnellength it means that x and y are translated. We need to "compensate" for this */
	float OffsetX0 = 0.047 * 7 * sinrot_3X;
	float OffsetY0 = 0.075 * 3 * cosrot_3Y;
	/* These get the new value at the and of the tunnelloop so we don't have to set them here */
	float OffsetX1, OffsetY1;

	for (j = 0; j < tunnellength; j++) {
		/* read the coordinates for 1 tunnel segment */
		for (i = 0; i < 12; i++) {
			X[i] = vdata[i][0] * 1.2;
			Y[i] = vdata[i][1] * 1.2;
		}

		/* Move the tunnel in the Z direction.
		   If Z is to big place new Z at the begin of the tunnel */
		Z0 = 4 + fmod(j + speed*dif,tunnellength) - 0.5 * tunnellength;
		Z1 = Z0 + 1;

		/* Twist and bent the tunnel (sinrot_3X, cosrot_3Y loops through a (co-)sinus table) */
		OffsetX1 = 7 * sinrot_3X * fmod(j * 0.047, 0.047);
		OffsetY1 = 3 * cosrot_3Y * fmod(j * 0.075, 0.075);

		/* Draw a tunnel segment */
		for (i = 0; i < 12; i++) {
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);
				glVertex3f(X[i] + OffsetX0, Y[i] + OffsetY0, Z0);
				if (i == 11) { // connect to the last quad to the first
					glTexCoord2f(1.0, 0.0);
					glVertex3f(X[0] + OffsetX0, Y[0] + OffsetY0, Z0);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(X[0] + OffsetX1, Y[0] + OffsetY1, Z1);
				} else {
					glTexCoord2f(1.0, 0.0);
					glVertex3f(X[i+1] + OffsetX0, Y[i+1] + OffsetY0, Z0);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(X[i+1] + OffsetX1, Y[i+1] + OffsetY1, Z1);
				}
				glTexCoord2f(0.0, 1.0);
				glVertex3f(X[i] + OffsetX1, Y[i] + OffsetY1, Z1);
			glEnd();
		}

		/* Make sure the new tunnel segment is connected to the last one */
		OffsetX0 = OffsetX1;
		OffsetY0 = OffsetY1;
	}
}

/* Calculations for the Super Ellipse */
void evalsuperellipse(double t1, double t2, double p1, double p2, XYZ *p)
{
        double tmp;
        double ct1, ct2, st1, st2;
        ct1 = cos(t1);
        ct2 = cos(t2);
        st1 = sin(t1);
        st2 = sin(t2);
        tmp  = SIGN(ct1) * pow(fabs(ct1),p1);
        p->x = tmp * SIGN(ct2) * pow(fabs(ct2),p2);
        p->y = SIGN(st1) * pow(fabs(st1),p1);
        p->z = tmp * SIGN(st2) * pow(fabs(st2),p2);
}

/* Creates the Super Ellipse surface */
void createsuperellipse(double pow1, double pow2, int n)
{
	glBindTexture (GL_TEXTURE_2D, texture[7]);
        int i,j;
        double theta1, theta2, theta3, delta;
        XYZ p, p1, p2;
        delta = 0.01 * TWOPI / n;
        for(j = 0; j<n/2; j++) {
                theta1 = j * TWOPI / (double)n - PID2;
                theta2 = (j+1) * TWOPI / (double)n - PID2;
                glBegin(GL_QUAD_STRIP);
                for(i = 0; i<=n; i++) {
                        if(i == 0 || i == n)
                                theta3 = 0;
                        else
                                theta3 = i * TWOPI / n;
				evalsuperellipse(theta2,theta3,pow1,pow2,&p);
				evalsuperellipse(theta2+delta,theta3,pow1,pow2,&p1);
				evalsuperellipse(theta2,theta3+delta,pow1,pow2,&p2);
				glTexCoord2f(i/(double)n,2*(j+1)/(double)n);
				glVertex3f(p.x,p.y,p.z);
				evalsuperellipse(theta1,theta3,pow1,pow2,&p);
				evalsuperellipse(theta1+delta,theta3,pow1,pow2,&p1);
				evalsuperellipse(theta1,theta3+delta,pow1,pow2,&p2);
				glTexCoord2f(i/(double)n,2*j/(double)n);
				glVertex3f(p.x,p.y,p.z);
			}
			glEnd();
        }
}

void scene2() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // make sure the buffers are cleared
	glPushMatrix ();
		glPushMatrix ();
			GLfloat light_ambient[] = {0.1, 0.0, 0.6, 1.0};
			GLfloat light_diffuse[] = {0.1, 0.0, 0.6, 1.0};
			GLfloat light_specular[] = {0.2, 0.0, 0.6, 1.0};
			GLfloat light_position[] = {0.0, 0.0, -45.0, 1.0};
			GLfloat fogColor[4] = {0.5, 0.0, 0.2, 1.0};

			// Set textures to use
			glBindTexture (GL_TEXTURE_2D, texture[3]);
			glEnable(GL_TEXTURE_2D);

			// Set lighting parameters
			glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
			glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
			glLightfv(GL_LIGHT0, GL_POSITION, light_position);

			// Enable light 0
			glEnable(GL_LIGHT0);
			glDepthFunc(GL_LESS);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_LIGHTING);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			// Enable fog
			glFogi(GL_FOG_MODE, GL_EXP);
			glFogfv(GL_FOG_COLOR, fogColor);
			glFogf(GL_FOG_DENSITY, 0.06);
			glEnable(GL_FOG);

			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
			tunnel(); // compute and draw my tunnel
		glPopMatrix();
		glPushMatrix ();
			lighton();
			glEnable (GL_TEXTURE_2D);	// Enable texture mapping.
			glBindTexture (GL_TEXTURE_2D, texture[1]);	// choose the texture to use
			glDisable(GL_FOG);
			glTranslatef (0.0,0.0,6.0);
			glPushMatrix();
				glRotatef(fmod(dif * 20, 360), sinrot_X, cosrot_Y, -sinrot_X);
				createsuperellipse(3.2 + cosrot_X * 1.2, 2.7 + cosrot_X * 1.3, 30);
			glPopMatrix();
			glDisable(GL_FOG);
			lightoff();
		glPopMatrix();
	glPopMatrix();

	glutSwapBuffers (); // show the buffer and compute the other.

}
