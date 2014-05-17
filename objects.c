#include "objects.h"

void
Random_XYZ ()
{
  int i;
  float x, y, z;
  srandom(time(0));
  
  for (i = 0; i < POINTS; i++)
  {
    x = (float) random() / (float) 0x7fffffff;
    Random_X[i] = (x * 1.6) - 0.8;
    y = (float) random() / (float) 0x7fffffff;
    Random_Y[i] = (y * 1.6) - 0.8;
    z = (float) random() / (float) 0x7fffffff;
    Random_Z[i] = (z * 1.6) - 0.8;
  }
}

void 
Pascal_XYZ ()
{
  const int n = 200;
  typedef long matrix[n][n];
  int i, j;
  double k, l;
  float x, y, z;
	int teller = 0;
  matrix Pascal;

  for (i = 0; i < n; i++) { Pascal[i][0] = 1; }
  
	Pascal[0][1] = 0;
  
	for (i = 0; i < n; i++)
  {
    for (j = 1; j <= i; j++)
    {
      Pascal[i][j] = Pascal[i - 1][j - 1] + Pascal[i - 1][j];
      k = (Pascal[i][j]);
      l = (Pascal[i - 1][j - 1]);
      x = (float) 1 / (tan (k) / cos (k));	// ziet er leuker uit op het scherm
      y = (float) 1 / (tan (k) / sin (l));
      z = (float) tan (k);
      			
			Pascal_X[teller] = x;
			Pascal_Y[teller] = y;
			Pascal_Z[teller] = z;
			teller += 1;
    }
    if (i != n - 1)
    {
      Pascal[i][i + 1] = 0;
    }
  }
}
