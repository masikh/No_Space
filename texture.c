#include "texture.h"
int enum_texture = 8; /* Number of used textures. */

int ImageLoad (char *filename, Image * image)
{
  FILE *file;
  unsigned long size;		// size of the image in bytes.
  unsigned long i;		// standard counter.
  unsigned short int planes;	// number of planes in image (must be 1) 
  unsigned short int bpp;	// number of bits per pixel (must be 24)
  char temp;			// used to convert bgr to rgb color.

  // make sure the file is there.
  if ((file = fopen (filename, "rb")) == NULL)
  {
    printf ("File Not Found : %s\n", filename);
    return 0;
  }

  // seek through the bmp header, up to the width/height:
  fseek (file, 18, SEEK_CUR);

  // read the width
  if ((i = fread (&image->sizeX, 4, 1, file)) != 1)
  {
    printf ("Error reading width from %s.\n", filename);
    return 0;
  }

  // read the height 
  if ((i = fread (&image->sizeY, 4, 1, file)) != 1)
  {
    printf ("Error reading height from %s.\n", filename);
    return 0;
  }
  printf ("\tres: %lux%lu\t", image->sizeX, image->sizeY);
  // calculate the size (assuming 24 bits or 3 bytes per pixel).
  size = image->sizeX * image->sizeY * 3;
	printf ("size: %luKb\t",size/1024);
	printf ("Loaded texture: %s\n", filename);
  // read the planes
  if ((fread (&planes, 2, 1, file)) != 1)
  {
    printf ("Error reading planes from %s.\n", filename);
    return 0;
  }
  if (planes != 1)
  {
    printf ("Planes from %s is not 1: %u\n", filename, planes);
    return 0;
  }

  // read the bpp
  if ((i = fread (&bpp, 2, 1, file)) != 1)
  {
    printf ("Error reading bpp from %s.\n", filename);
    return 0;
  }
  if (bpp != 24)
  {
    printf ("Bpp from %s is not 24: %u\n", filename, bpp);
    return 0;
  }

  // seek past the rest of the bitmap header.
  fseek (file, 24, SEEK_CUR);

  // read the data. 
  image->data = (char *) malloc (size);
  if (image->data == NULL)
  {
    printf ("Error allocating memory for color-corrected image data");
    return 0;
  }

  if ((i = fread (image->data, size, 1, file)) != 1)
  {
    printf ("Error reading image data from %s.\n", filename);
    return 0;
  }

  for (i = 0; i < size; i += 3)
  {				// reverse all of the colors. (bgr -> rgb)
    temp = image->data[i];
    image->data[i] = image->data[i + 2];
    image->data[i + 2] = temp;
  }

  // we're done.
  return 1;
}

// Load Bitmaps And Convert To Textures
void
LoadGLTextures (void)
{
  int i;
	char *files[] = { "./data/sun.bmp",   // glBindTexture (GL_TEXTURE_2D, texture[0]);
			"./data/texture0.bmp", 	// glBindTexture (GL_TEXTURE_2D, texture[i]);
			"./data/texture1.bmp",  // glBindTexture (GL_TEXTURE_2D, texture[N]);
			"./data/texture2.bmp",
			"./data/background.bmp",
			"./data/eof.bmp",
			"./data/borg.bmp",
			"./data/texture3.bmp"};
	// Load Texture
	for (i = 0; i < enum_texture; i++) {
		Image *image[i];
  	// allocate space for texture
  	image[i] = (Image *) malloc (sizeof (Image));

	  if (image[i] == NULL) { printf ("Error allocating space for image"); exit (0); }
	  if (!ImageLoad (files[i], image[i])) { exit (1); }
		
  	glGenTextures (enum_texture, &texture[i]);
    	glBindTexture (GL_TEXTURE_2D, texture[i]);
    	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
  	glTexImage2D (GL_TEXTURE_2D, 0, 3, image[i]->sizeX, image[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image[i]->data);
  	gluBuild2DMipmaps (GL_TEXTURE_2D, 3, image[i]->sizeX, image[i]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, image[i]->data);
	}
	printf("\n");
};
