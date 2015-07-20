#include "Pingiel3D.h"

void gracz(int x, int y, int z)
{
	glBegin(GL_TRIANGLE_STRIP);//podobno wydajniej niz quad
	glTexCoord2d(0, 0);	glVertex3d(x-8, 10, 0);
	glTexCoord2d(0, 1); glVertex3d(x-8, 0, 0);
	glTexCoord2d(1, 0); glVertex3d(x+8, 10, 0);
	glTexCoord2d(1, 1); glVertex3d(x+8, 0, 0);
	glTexCoord2d(0, 0);	glVertex3d(x+8, 10, 8);
	glTexCoord2d(0, 1); glVertex3d(x+8, 0, 8);
	glTexCoord2d(1, 0); glVertex3d(x-8, 10, 8);
	glTexCoord2d(1, 1); glVertex3d(x-8, 0, 8);
	glTexCoord2d(0, 0);	glVertex3d(x+8, 10, 0);
	glTexCoord2d(0, 0); glVertex3d(x-8, 0, 0);
	glTexCoord2d(0, 0); glVertex3d(x-8, 0, 0);
	glTexCoord2d(0, 1); glVertex3d(x-8, 0, 8);
	glTexCoord2d(1, 0);	glVertex3d(x+8, 0, 0);
	glTexCoord2d(1, 1); glVertex3d(x+8, 0, 8);
	glEnd();
}
void plansza()
{

	glBegin(GL_TRIANGLE_STRIP);//podobno wydajniej niz quad
		glTexCoord2d(0, 0);	glVertex3d(0, -10, 0);
		glTexCoord2d(0, 1); glVertex3d(0, 0, 0);
		glTexCoord2d(1, 0); glVertex3d(80, -10, 0);
		glTexCoord2d(1, 1); glVertex3d(80, 0, 0);
		glTexCoord2d(0, 0);	glVertex3d(80, -10, 400);
		glTexCoord2d(0, 1); glVertex3d(80, 0, 400);
		glTexCoord2d(1, 0); glVertex3d(0, -10, 400);
		glTexCoord2d(1, 1); glVertex3d(0, 0, 400);
		glTexCoord2d(0, 0);	glVertex3d(80, -10, 0);
		glTexCoord2d(0, 0); glVertex3d(0, 0, 0);
		glTexCoord2d(0, 0); glVertex3d(0, 0, 0);
		glTexCoord2d(0, 1); glVertex3d(0, 0, 400);
		glTexCoord2d(1, 0);	glVertex3d(80, 0, 0);
		glTexCoord2d(1, 1); glVertex3d(80, 0, 400);
	glEnd();

}