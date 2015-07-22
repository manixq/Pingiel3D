#define _CRT_SECURE_NO_DEPRECATE//bez tego blad fopen
#define PINGIEL_ICON 1
#define PINGIEL_MENU 102
#define ID_MENU_EXIT 103
#define ID_MENU_ABOUT 104
#define ID_MENU_WINSHOW 105
#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\GLAux.h>
#include <stdio.h>
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"glaux.lib")

GLuint* wyslij();

bool keys[];
void rysuj(GLUquadricObj *quadric);
void setFog();
void plansza();
void gracz(int x, int y, int z);
void ball(GLUquadricObj *quadric,double x, double y, double z, int r);
