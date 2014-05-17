#include "main.h"

int WIDTH = 1280;		// screen resolution
int HEIGHT = 1024;
int SINCOSPOS = 0; // counter for the position in our sincos  table
float center_x = 0.0;
float center_y = 0.0;
float center_z = 0.0;
float scale_X = 1.0;
float scale_Y = 1.0;
float scale_Z = 1.0;
double frame = 0;
double FPS;
int lastCount = 0;
int counter = 0;

void
Quit (int returnCode)
{
  /* clean up the window */
//  Mix_CloseAudio ();
//  SDL_QuitSubSystem(SDL_INIT_AUDIO);
//  SDL_Quit ();
  glutDestroyWindow(winIdMain);
  printf ("Exit gracefully\n");
  exit (returnCode);
  /* and exit appropriately */
}


void
Display()
{
	// dif is a timer. e.g. dif at t=0 = 0.00 seconds, dif at t=i = 12.43 seconds.
	if (dif < 27.13) {
		scene1();
	}
	if (dif > 27.13 && dif < 67.96) {
		scene2();
	}
	if (dif > 67.96 && dif < 224.84) {
		scene3(dif);
	}
	if (dif > 224.84 && dif < 236.00 ) {
		scene4();
	}
	if (dif > 235.57) {
		glFlush();
		Quit(0);
	}
};

void
keyboard (unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:			/* ESC */
		Quit(1);
  case 'w':
  case 'W':			/* Window size (Additional) : w/W */
    if (WIDTH == 1024)
    {
      WIDTH = 800;
      HEIGHT = 640;
      glutReshapeWindow (WIDTH, HEIGHT);
      glutPositionWindow (100, 100);
      printf ("Set resolution to: 800x600\n");
    }
    else if (WIDTH == 800)
    {
      WIDTH = 1024;
      glutFullScreen ();
      printf ("Set resolution to: FullScreen\n");
    }
		break;
  case 'a':
		glScalef(scale_X + 0.1, scale_Y + 0.1, scale_Z + 0.1);
		break;
  case 'z':
		glScalef(scale_X - 0.1, scale_Y - 0.1, scale_Z - 0.1);
    break;
  }
}

/* Callback function for reshaping the main window */
void
mainReshape (int w, int h)
{
  	glViewport (0, 0, w, h);
  	glMatrixMode (GL_PROJECTION);
  	gluPerspective (
		40.0,		/* Field of view in degree */
		1.25,		/* aspect ratio e.g. 1280 divided by 1024 */
		1.0,		/* Z near */
		300.0 /* Z far */ );
  	gluLookAt (
		0.0, 0.0, 10.0,	/* Eye is at */
		center_x, center_y, center_z,	/* Center is at */
		0.0, 1.0, 0.0 /* Up is in positive Y direction */ );
};

void sincostable(void)
{
	int i;

  for (i = 0; i < 7200; i++)
	{
		floatsin[i]=(sin(i * PI / 3600 ));
		floatcos[i]=(cos(i * PI / 3600 ));
		floatsin3[i]=(sin( i * PI / 120  ));
		floatcos3[i]=(cos( i * PI / 120  ));
	}
}

void
idle ()
{
	/* Redisplay every thing */
	glutPostRedisplay ();

	/* The result of dif is the timer for all scene's */
	dif = 0.001 * glutGet(GLUT_ELAPSED_TIME);
	//printf("DIF: %.3F\n", dif);
	fmod(dif,300);
	/* Calculate FPS */
	frame++;
	if( (dif - lastCount) > 2 ) {
		FPS = (int) ( frame / (dif - lastCount) );
		lastCount = dif;
		frame = 0;
  		//printf("FPS: %.0f\n", FPS);
	}

	/* Loop through my sinus and cosinus tables */
	if (SINCOSPOS > 7198)
	{
		SINCOSPOS = 0;
		//printf("DIF: %.3F\n", dif);
	}
	else
	{
		SINCOSPOS += 1;
		sinrot_X = floatsin[SINCOSPOS];	sinrot_Y = floatsin[SINCOSPOS];
		cosrot_X = floatcos[SINCOSPOS];	cosrot_Y = floatcos[SINCOSPOS];
		sinrot_3X = floatsin3[SINCOSPOS]; sinrot_3Y = floatsin3[SINCOSPOS];
		cosrot_3X = floatcos3[SINCOSPOS]; cosrot_3Y = floatcos3[SINCOSPOS];
	}
};

//void music () {
//  /* start SDL with audio support */
//  if (SDL_Init (SDL_INIT_AUDIO) == -1)
//  {
//    printf ("SDL_Init: %s\n", SDL_GetError ());
//    Quit (1);
//  }
//
//  if (Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
//  {
//    printf ("Mix_OpenAudio: %s\n", Mix_GetError ());
//    Quit (1);
//  }
//
//  /* Load music */
//  soundtrack = Mix_LoadMUS ("./data/soundtrack.mp3");
//  if (!soundtrack)
//  {
//    printf ("Mix_LoadMUS(\"music.mp3\"): %s\n", Mix_GetError ());
//    // this might be a critical error...
//  }
//  else
//  {
//    printf ("\tLoaded: ./data/soundtrack.mp3\n\n");
//    int loop = 1;
//    Mix_PlayMusic (soundtrack, loop); // loop = number of times the song gets played
//  }
//}

//int main (int argc, char **argv)
int main(int argc, char*argv[])
{
  printf ("Please injoy the demo 'There is no space' by Robert Nagtegaal (c)2004\n\n");

  /* Start Music */
  printf ("Initializing SDL music support:\n");
//  music();

  /* Precalculation */
  printf("Doing precalculations:\n");
  sincostable();
  printf("\t(co)sinus tables\n");
  Pascal_XYZ();
  printf("\tTriangle of Pascal\n");
  Random_XYZ();
  printf("\tRandom floats\n\n");

  /* Glut initializations */
  glutInit (&argc, argv);			// get commandline arguments
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowPosition (5, 5);		// geometrie +5+5,w,h
  glutInitWindowSize (WIDTH, HEIGHT);		// ^^^^^^^^^
  winIdMain = glutCreateWindow (TITLE);		// create a window called TITLE
  glutKeyboardFunc (keyboard);			// some keybindings
  //glutFullScreen();
  printf("Loading textures:\n");
  // load the textures.
  LoadGLTextures ();

  glutSetCursor (GLUT_CURSOR_NONE);		// no mouse pointer
  glutReshapeFunc (mainReshape);		// if windows is resized
  glutDisplayFunc (Display);			// Let's draw something
  glutIdleFunc (idle);				// idle loop for timer increment
  glutMainLoop ();				// keep on looping in this main function
  return 0;					// die clean
};
