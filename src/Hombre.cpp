#include "stdafx.h"
#include "Hombre.h"
#include "glut.h"
#include "Interaccion.h"

#define PI 3.1415926535


Hombre::Hombre()
{
	altura = 3.0f;
	radio = 1.5f;
	velocidad = 0;
	ancho = 1.0f;
	cuerpo_dcha.setLimites(ancho, -radio - altura, ancho, -radio);
	cuerpo_dcha.setColor(255, 0, 0);
	cuerpo_izq.setLimites(-ancho, -radio - altura, -ancho, -radio);
	cuerpo_izq.setColor(255, 0, 0);
		//pared_izq.SetLimites(-30, 0, -30, 35);
}



Hombre::~Hombre()
{
}

void Hombre::dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(170, 0, 0);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glBegin(GL_QUADS);
	glVertex2f(-ancho, -radio);
	glVertex2f(ancho,-radio);
	glVertex2f(ancho,-altura-radio);
	glVertex2f(-ancho,-altura-radio);
	glEnd();
	cuerpo_dcha.dibujaCuerpo();
	cuerpo_izq.dibujaCuerpo();
	/*glBegin(GL_LINES);
	glColor3ub(240, 240, 255);
	glVertex2f(0, 0);
	glVertex2f(0, 13.0f);
	glEnd();*/
	glEnable(GL_LIGHTING);
	glTranslatef(-posicion.x, -posicion.y, 0);

}

void Hombre::mueve(float t) {
	posicion = posicion + velocidad*t;
	if(posicion.y>=0) velocidad.y = velocidad.y - 9.8*t;
}

void Hombre::setRadio(float r) {
	radio = r;
}

void Hombre::control_awsd(unsigned char key) {
	if (key == 'a') setVel(-10.0f, velocidad.y);
	if (key == 'd') setVel(10.0f, velocidad.y);
	if (key == 'w'&&posicion.y <= altura +radio+ 1.0f) setVel(velocidad.x, 13.0f);
	if (key == 's'&&posicion.y <= altura + radio + 1.0f) setVel(0.0f, velocidad.y);

}
void Hombre::control_jil(unsigned char key) {
	if (key == 'j') setVel(-10.0f, velocidad.y);
	if (key == 'l') setVel(10.0f, velocidad.y);
	if (key == 'i'&&posicion.y<=altura+radio+0.1f) setVel(velocidad.x, 13.0f);
	if (key == 'k'&&posicion.y <= altura + radio + 1.0f) setVel(0.0f, velocidad.y);
}
void Hombre::control_Dirkeys(unsigned char key) {
	switch (key) { 
	case GLUT_KEY_LEFT:  
		setVel(-5.0f, velocidad.y);   
		break;  
	case GLUT_KEY_RIGHT:  
		setVel(5.0f, velocidad.y);   
		break; 
	case GLUT_KEY_UP:
		setVel(velocidad.x, 5.0f);
		break;
	}
}

float Hombre::getRadio() {
	return radio;
}
float Hombre::getAltura() {
	return altura;
}

float Hombre::getArea() {
	return (radio*radio*PI);
}
int Hombre::getMarcador() {
	return marcador;
}
void Hombre::setMarcador(int i) {
	marcador = i;
}
void Hombre::sumarMarcador() {
	marcador++;
}
bool Hombre::reboteCuerpo(Esfera &e){
	if(Interaccion::rebote(e, cuerpo_dcha)||Interaccion::rebote(e, cuerpo_izq)) return true;
	return false;
}
int Hombre::getToques() { return toques; }
void Hombre::setToques(int t) { toques = t; }