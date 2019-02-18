#include "stdafx.h"
#include "ETSIDI.h"
#include "Pared.h"
#include <glut.h>
#include "Interaccion.h"


Pared::Pared()
{
	rojo = verde = azul = 255;
}
Pared::~Pared()
{
}
void Pared::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}
void Pared::setLimites(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
Vector2D Pared::getLimite(int i) {
	switch (i) {
	case 1: return limite1;
	case 2: return limite2;
	default: exit(1);
	}
}
void Pared::dibuja() {
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(rojo, verde, azul);
	glVertex3d(limite1.x, limite1.y, 10);
	glVertex3d(limite2.x, limite2.y, 10);
	glVertex3d(limite2.x, limite2.y, -10);
	glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}
void Pared::dibuja(int i) {
	glEnable(GL_TEXTURE_2D);
	switch (i) {
	case 1:	
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("..\\textures\\publicofutbol.png").id);
		break;
	case 2:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("..\\textures\\arena.png").id);
		break;
	case 3:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("..\\textures\\cielo.png").id);
		break;
	default:
		break;
	}
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(rojo, verde, azul);
	glTexCoord2d(1, 1);
	glVertex3d(limite1.x, limite1.y, 10);

	glTexCoord2d(1, 0);
	glVertex3d(limite2.x, limite2.y, 10);

	glTexCoord2d(0, 0);
	glVertex3d(limite2.x, limite2.y, -10);

	glTexCoord2d(0, 1);
	glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
void Pared::dibujaCuerpo() {
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(rojo, verde, azul);
	glVertex3d(limite1.x, limite1.y, 0.5);
	glVertex3d(limite2.x, limite2.y, 0.5);
	glVertex3d(limite2.x, limite2.y, -0.5);
	glVertex3d(limite1.x, limite1.y, -0.5);
	glEnd();
	glEnable(GL_LIGHTING);
}
float Pared::distancia(Vector2D punto, Vector2D *direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).Unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u*v;
	float distancia = 0;
	if (valor<0)
		dir = u;
	else if (valor>longitud)
		dir = (punto - limite2);
	else
		dir = u - v*valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.Unitario();
	return distancia;
}
/*void Pared::dibujaFondo() {

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
}*/
