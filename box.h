// Cubical box
int box () {
  glBegin(GL_LINES);  

	glVertex3f( 0.8f, 0.8f, -0.8f); glVertex3f( 0.5f, 0.8f, -0.8f);   
	glVertex3f( 0.8f, 0.8f, -0.8f); glVertex3f( 0.8f, 0.5f, -0.8f);   
	glVertex3f( 0.8f, 0.8f, -0.8f); glVertex3f( 0.8f, 0.8f, -0.5f); 
	
	glVertex3f( 0.8f, -0.8f, -0.8f); glVertex3f( 0.5f, -0.8f, -0.8f);
	glVertex3f( 0.8f, -0.8f, -0.8f); glVertex3f( 0.8f, -0.5f, -0.8f);
	glVertex3f( 0.8f, -0.8f, -0.8f); glVertex3f( 0.8f, -0.8f, -0.5f);
	
	glVertex3f( -0.8f, 0.8f, -0.8f); glVertex3f( -0.5f, 0.8f, -0.8f);    
	glVertex3f( -0.8f, 0.8f, -0.8f); glVertex3f( -0.8f, 0.5f, -0.8f);    
	glVertex3f( -0.8f, 0.8f, -0.8f); glVertex3f( -0.8f, 0.8f, -0.5f);    

	glVertex3f( -0.8f, -0.8f, -0.8f); glVertex3f( -0.5f, -0.8f, -0.8f);
	glVertex3f( -0.8f, -0.8f, -0.8f); glVertex3f( -0.8f, -0.5f, -0.8f);
	glVertex3f( -0.8f, -0.8f, -0.8f);	glVertex3f( -0.8f, -0.8f, -0.5f);

  glVertex3f( 0.8f, 0.8f, 0.8f); glVertex3f( 0.5f, 0.8f, 0.8f);  
	glVertex3f( 0.8f, 0.8f, 0.8f); glVertex3f( 0.8f, 0.5f, 0.8f);  
	glVertex3f( 0.8f, 0.8f, 0.8f); glVertex3f( 0.8f, 0.8f, 0.5f); 
 
  glVertex3f( 0.8f, -0.8f, 0.8f); glVertex3f( 0.5f, -0.8f, 0.8f);
  glVertex3f( 0.8f, -0.8f, 0.8f); glVertex3f( 0.8f, -0.5f, 0.8f);
  glVertex3f( 0.8f, -0.8f, 0.8f); glVertex3f( 0.8f, -0.8f, 0.5f);
	
  glVertex3f( -0.8f, 0.8f, 0.8f); glVertex3f( -0.5f, 0.8f, 0.8f);
  glVertex3f( -0.8f, 0.8f, 0.8f); glVertex3f( -0.8f, 0.5f, 0.8f);
  glVertex3f( -0.8f, 0.8f, 0.8f); glVertex3f( -0.8f, 0.8f, 0.5f);
 
	glVertex3f( -0.8f, -0.8f, 0.8f); glVertex3f( -0.5f, -0.8f, 0.8f); 
	glVertex3f( -0.8f, -0.8f, 0.8f); glVertex3f( -0.8f, -0.5f, 0.8f);
	glVertex3f( -0.8f, -0.8f, 0.8f); glVertex3f( -0.8f, -0.8f, 0.5f);

	glEnd(); 
	return 0;
}
