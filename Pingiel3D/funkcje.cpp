#include "Pingiel3D.h"
struct player
{
	float x, z;
	float oX;
};

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
	static int x = 0;
	glRotatef(x++, 0, 1, 0);
	plansza();
	gracz(5,5,5);
}