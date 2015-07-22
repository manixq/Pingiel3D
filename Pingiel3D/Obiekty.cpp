#include "Pingiel3D.h"
GLuint* textures = wyslij();

void gracz(int x, int y, int z)
{
	if (z<200)
		glBindTexture(GL_TEXTURE_2D, textures[1]);
	else
		glBindTexture(GL_TEXTURE_2D, textures[2]);
	glBegin(GL_TRIANGLE_STRIP);//podobno wydajniej niz quad
		glTexCoord2d(1, 1);	glVertex3d(x-8, 10, z);
		glTexCoord2d(1, 0); glVertex3d(x-8, 0, z);
		glTexCoord2d(0, 1); glVertex3d(x+8, 10, z);
		glTexCoord2d(0, 0); glVertex3d(x+8, 0, z);
		glTexCoord2d(1, 1);	glVertex3d(x+8, 10, z+10);
		glTexCoord2d(1, 0); glVertex3d(x+8, 0, z+10);
		glTexCoord2d(0, 1); glVertex3d(x-8, 10, z+10);
		glTexCoord2d(0, 0); glVertex3d(x-8, 0, z+10);
		glTexCoord2d(1, 1);	glVertex3d(x-8, 10, z);
		glTexCoord2d(0, 0); glVertex3d(x-8, 0, z);
		glTexCoord2d(0, 1); glVertex3d(x-8, 10, z);
		glTexCoord2d(1, 1); glVertex3d(x-8, 10, z+10);
		glTexCoord2d(0, 1);	glVertex3d(x+8, 10, z);
		glTexCoord2d(1, 1); glVertex3d(x+8, 10, z+10);
	glEnd();
}

void ball(GLUquadricObj *quadric,double x, double y, double z, int r)
{
	glPushMatrix();
		
		glTranslatef(x, y, z);
		gluSphere(quadric, r, 10, 5);
	glPopMatrix();
}

void plansza()
{
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glBegin(GL_TRIANGLE_STRIP);//podobno wydajniej niz quad
		glTexCoord2d(0, 0);	glVertex3d(0, -10, 0);
		glTexCoord2d(0, 1); glVertex3d(0, 0, 0);
		glTexCoord2d(1, 0); glVertex3d(80, -10, 0);
		glTexCoord2d(1, 1); glVertex3d(80, 0, 0);
		glTexCoord2d(0, 0);	glVertex3d(80, -10, 400);
		glTexCoord2d(0, 1); glVertex3d(80, 0, 400);
		glTexCoord2d(1, 0); glVertex3d(0, -10, 400);
		glTexCoord2d(1, 1); glVertex3d(0, 0, 400);
		glTexCoord2d(0, 0);	glVertex3d(0, -10, 0);
		glTexCoord2d(0, 0); glVertex3d(0, 0, 0);
		glTexCoord2d(0, 0); glVertex3d(0, 0, 0);
		glTexCoord2d(0, 1); glVertex3d(0, 0, 400);
		glTexCoord2d(1, 0);	glVertex3d(80, 0, 0);
		glTexCoord2d(1, 1); glVertex3d(80, 0, 400);
	glEnd();

}