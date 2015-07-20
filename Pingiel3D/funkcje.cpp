#include "Pingiel3D.h"


struct player
{
	int x=5, z=5;
};

struct ball
{
	float x, y, z;
	int r;
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
void bPhys(ball x)
{

}

struct rect
{	
	float x=50, y=0,z=250;
	float width=100,height=500,bottom=0;
};

void setFog()
{
	static float fogColor[] = {0.0f, 0.0f, 0.0f, 1.0f};
	static float fogDensity = 0.002f;
	glFogi(GL_FOG_MODE, GL_EXP);//zalezy od fogdensity f=e^(-density*z)
	glFogf(GL_FOG_DENSITY, fogDensity);
	glFogfv(GL_FOG_COLOR, fogColor);

}

void rysuj()
{	
	static player p1, p2;
	
	
	plansza();
	if (keys[VK_LEFT] && pPhys(p1))
		p1.x++;
	if (keys[VK_RIGHT] && pPhys(p1))
		p1.x--;

	gracz(p1.x,5,p1.z);
}