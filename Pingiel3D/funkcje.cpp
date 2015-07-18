#include "Pingiel3D.h"

void rysuj()
{
	static GLfloat rot = 0.0;
	glRotatef(rot++, 1, 1, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d(1, 1);	glVertex3d(50, 0, 50);
		glTexCoord2d(0, 1);	glVertex3d(0, 0, 50);
		glTexCoord2d(1, 0);	glVertex3d(50, 0, 0);
		glTexCoord2d(0, 0);	glVertex3d(0, 0, 0);
		glTexCoord2d(0, 0);	glVertex3d(0, 0, 0);
		glTexCoord2d(0, 1); glVertex3d(0, 50, 0);
		glTexCoord2d(1, 0); glVertex3d(50, 0, 0);
		glTexCoord2d(1, 1); glVertex3d(50, 50, 0);
		glTexCoord2d(0, 0);	glVertex3d(50, 0, 50);
		glTexCoord2d(0, 1); glVertex3d(50, 50, 50);
		glTexCoord2d(1, 0); glVertex3d(0, 0, 50);
		glTexCoord2d(1, 1); glVertex3d(0, 50, 50);
		glTexCoord2d(0, 0);	glVertex3d(0, 0, 0);
		glTexCoord2d(0, 1); glVertex3d(0, 50, 0);
		glTexCoord2d(0, 1); glVertex3d(0, 50, 0);
		glTexCoord2d(1, 1); glVertex3d(50, 50, 0);
		glTexCoord2d(0, 0);	glVertex3d(0, 50, 50);
		glTexCoord2d(1, 0); glVertex3d(50, 50, 50);
		
	glEnd();
	
}