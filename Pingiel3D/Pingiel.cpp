#define _CRT_SECURE_NO_DEPRECATE//bez tego blad fopen
#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\GLAux.h>
#include <stdio.h>
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"glaux.lib")
#include "Pingiel3D.h"

GLuint texture[3];
GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };
bool keys[256];

AUX_RGBImageRec *LoadBMP(char* Filename)//teksturki
{
	FILE *File = NULL;
	if (!Filename) return NULL;
	File = fopen(Filename, "r");//sprawdz czy istnieje
	if (File)
	{
		fclose(File);
		return auxDIBImageLoad(Filename);
	}
	return NULL;
}

int LoadGLTexture()
{
	int Status = FALSE;
	AUX_RGBImageRec *TextureImage[1];//rezerwujemy miejsce na teksture
	memset(TextureImage, 0, sizeof(void*) * 1); //ustawiamy na 0
	if (TextureImage[0] = LoadBMP("pliki/tex.bmp"))
	{
		Status = true;
		glGenTextures(3, &texture[0]);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//filtrowanie liniowe
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//filtrowanie liniowe
	}
	if (TextureImage[0])
	{
		if (TextureImage[0]->data)
		{
			free(TextureImage[0]->data);//zwolnij pamiec tekstury obrazu
		}
		free(TextureImage[0]);//zwolnij pamiec struktury obrazu
	}
	return Status;
}


int InitGL(GLvoid)                              // All Setup For OpenGL Goes Here
{
	if (!LoadGLTexture())                          // Jump To Texture Loading Routine ( NEW )
	{
		return FALSE;                           // If Texture Didn't Load Return FALSE ( NEW )
	}
	glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping ( NEW )
	glShadeModel(GL_SMOOTH);                        // Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);                   // Black Background
	glClearDepth(1.0f);                         // Depth Buffer Setup
	//glEnable(GL_DEPTH_TEST);                        // Enables Depth Testing
	glDepthFunc(GL_LEQUAL);                         // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);          // Really Nice Perspective Calculations
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	return TRUE;                                // Initialization Went OK
}

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
{
	if (height == 0) height = 1;//pamietaj cholero nie dziel przez zero

	glViewport(0, 0, width, height);//resetowanie aktualnego widoku

	glMatrixMode(GL_PROJECTION);//ust. macierzy projekcji
	glLoadIdentity();//reset m. proj.

	gluPerspective(45.0f,(GLfloat)width / (GLfloat)height, 0.1f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);//macierz modelu
	glLoadIdentity();//reset macierzy modelu
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		if (HIWORD(wParam) == 0)
			switch (LOWORD(wParam))
			{
			case ID_MENU_EXIT:PostQuitMessage(0);
				break;
			case ID_MENU_ABOUT: MessageBox(0, "Multimedia 4fun", "Info", MB_OK);
				break;
			case ID_MENU_WINSHOW: 
				break;
			}
		break;
	case WM_CREATE:
		break;
	case WM_PAINT:
		break;
	case WM_SIZE:
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_DESTROY:PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}


int DrawGLScene(GLvoid)
{
	static GLfloat rot = 0.0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//wyzerowanie bufora kolorow i glebokosci
	
	glLoadIdentity();
	
	glTranslatef(0, 0, -25);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	glNormal3d(0, -1, 0);//wektor normalny
	glTexCoord2f(1.0f, 1.0f);
	glVertex3d(8, 6, 3);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3d(0, 6, 3);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3d(5, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3d(-10, 0, 0);
	glEnd();
	
	return 1;
}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW |CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(PINGIEL_ICON));
	wc.hCursor = 0;
	wc.hbrBackground = 0;
	wc.lpszMenuName = MAKEINTRESOURCE(PINGIEL_MENU);
	wc.lpszClassName = "PingielClass";

	if (!RegisterClass(&wc))	
		return false;

	MessageBox(0, "hejo", "okienko", MB_OK);

	int horizontal=GetSystemMetrics(16);
	int vertical = GetSystemMetrics(17);

	HWND hWnd = CreateWindow(wc.lpszClassName, "Okno", WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU, 0, 0,horizontal, vertical, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL)
		return false;

	static PIXELFORMATDESCRIPTOR pfd=  //struktura formatu pixeli
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,//numerwersji
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		16,//tryb koloru
		0,0,0,0,0,0,//ignorowane bity koloru
		0,//brak kanalu alpha
		0,//ignorowanie rpzesuniecia
		0,//brak akumulatora
		0,0,0,0,//ignorowane przesuniecie akumulatora
		16,//16bitowy bufor glebokosci
		0,//no stencil buffer
		0,//no auxiliary buffer
		PFD_MAIN_PLANE,//glowna warstwa rysowania
		0,//zarezerwowane
		0,0,0//ignorowanie warstwy maski

	};

	HDC hDC = NULL;//kontekst urzadzenia
	HGLRC hRC = NULL;//kontekst renderowania
	GLuint PixelFormat;//styl pixeli

	if (!(hDC = GetDC(hWnd))) return 0;//pobranie kontekstu
	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))return 0;//wyszukiwanie formatu pixeli
	if (!SetPixelFormat(hDC, PixelFormat, &pfd)) return 0;//ust. formatu pixeli
	if (!(hRC = wglCreateContext(hDC)))return 0;//pobvranie kontekstu renderowania
	if (!wglMakeCurrent(hDC, hRC))return 0; //uruchomienie kontekstu renderowania

	ShowWindow(hWnd, iCmdShow);
	SetForegroundWindow(hWnd);
	SetFocus(hWnd);
	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
									// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}
	BOOL done = false;
	MSG msg;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))//czy jest zdarzenie do obslugi?
		{
			if (msg.message == WM_QUIT) done = TRUE;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			DrawGLScene();
			SwapBuffers(hDC);
		}
		
		
	}
	if (hRC)
	{
		wglMakeCurrent(NULL, NULL);//usuw. kontekstu rend.
		wglDeleteContext(hRC);//usuw. kontekstu rend.
		hRC = NULL;//wyzerowanie kontekstu rend.
	}
	if (hDC && !ReleaseDC(hWnd, hDC)) { hDC = NULL; }//wyzerowanie kontekstu
	if (hWnd&& !DestroyWindow(hWnd)){ hWnd = NULL; }//wyzerowanie uchwytu okienka

	return 0;
}

