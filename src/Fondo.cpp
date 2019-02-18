#include "stdafx.h"
#include "ETSIDI.h"
#include "glut.h"
#include "Fondo.h"


Fondo::Fondo()
{
}


Fondo::~Fondo()
{
}

void Fondo::dibuja() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("C:\\Users\\user\\Documents\\UNIVERSIDAD\\Infor3o\\Juego Clase\\HeadVolley\\textures\\publicofutbol.png").id);

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(rojo, verde, azul);
	glTexCoord2d(1, 1);
	glVertex3d(limite1.x, limite1.y, -10);

	glTexCoord2d(1, 0);
	glVertex3d(limite1.x, limite2.y, -10);

	glTexCoord2d(0, 0);
	glVertex3d(limite2.x, limite2.y, -10);

	glTexCoord2d(0, 1);
	glVertex3d(limite2.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}