#include "Pingiel3D.h"
#include <cmath>
static int tab[2];
struct player
{
	int x=5, z=400;
};
struct pilka
{
	double x= 20;
	double y = 5;
	double z = 400;
};
bool pPhys(player& x)
{
	if (x.x < 0 )
	{
		x.x = 0;
		return false;
	}
	if (x.x > 80)
	{
		x.x = 80;
		return false;
	}
		return true;
}

int* bPhys(player p1,player p2,pilka gala)
{ 
	player ptab[2] = { p1, p2 };
	for (int i = 0; i < 2; i++)
		if ((gala.z  == ptab[i].z) && (gala.x<(ptab[i].x + 10)) && (gala.x>(ptab[i].x - 10)))
		{
			tab[0] = -1;
			tab[1] = ptab[i].x - gala.x;
			return tab;
		}
	tab[0] = 1;
	return tab;
}



void setFog()
{
	static float fogColor[] = {0.0f, 0.0f, 0.0f, 1.0f};
	static float fogDensity = 0.001f;
	glFogi(GL_FOG_MODE, GL_EXP);//zalezy od fogdensity f=e^(-density*z)
	glFogf(GL_FOG_DENSITY, fogDensity);
	glFogfv(GL_FOG_COLOR, fogColor);

}

void rysuj(GLUquadricObj *quadric)
{	
	static double s = 0.0, x=0.0, z = 1;

	static player p1, p2;	
	static pilka gala;

	plansza();
	
	if (keys[VK_LEFT] && pPhys(p1))
		p1.x--;
	if (keys[VK_RIGHT] && pPhys(p1))
		p1.x++;
	gracz(p1.x,5,p1.z);//rysowanie gracza

	p2.z = 0;
	if (keys['D'] && pPhys(p2))
		p2.x++;
	if (keys['A'] && pPhys(p2))
		p2.x--;
	gracz(p2.x, 5, p2.z);//rysowanie gracza
	if (gala.y < 0)	s = 0.0;
	int* i;
	i = bPhys(p1, p2, gala);
	
	z = z*i[0];

	ball(quadric,gala.x+=i[1]/30.0, gala.y=12*sin(s++/60), gala.z-=z*2,5);
	if (keys['P'])
	{
		gala.x = 40;
		gala.z = 200;
	}
	
}