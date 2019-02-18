#include "stdafx.h"
#include <ETSIDI.h>
#include "glut.h"

#include "CoordinadorHeadVolley.h"
#include <Mundo.h>
CoordinadorHeadVolley HeadVolley;


void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
	//glutFullScreen();
	ETSIDI::playMusica("..\\sounds\\sonido estadio.mp3", false);
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);

	glutMainLoop();
	return 0;
}

void OnDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	HeadVolley.dibuja();

	glutSwapBuffers();
}
void OnTimer(int value)
{
	//ETSIDI::playMusica("C:\\Users\\user\\Documents\\UNIVERSIDAD\\Infor3o\\Juego Clase\\HeadVolley\\sounds\\FOTINT02.mp3", false);
	HeadVolley.mueve();
	glutTimerFunc(50, OnTimer, 0);
	glutPostRedisplay();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	HeadVolley.control(key);
	glutPostRedisplay();
}