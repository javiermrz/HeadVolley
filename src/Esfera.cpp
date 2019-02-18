#include "stdafx.h"
#include "ETSIDI.h"
#include <glut.h>
#include "Esfera.h"

#define PI 3.1415926535

Esfera::Esfera():sprite("C:\\Users\\user\\Documents\\UNIVERSIDAD\\Infor3o\\Juego Clase\\HeadVolley\\textures\\pelota.png",1,1) {
	aceleracion.y = -17.0f;
	aceleracion.x = 0;
	sprite.setCenter(0.9, 0.9);
	sprite.setSize(2, 2);
}
/*
Esfera::Esfera(float rad, float x, float y, float vx, float vy) {
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	aceleracion.y = -9.8f;
}*/
Esfera::~Esfera() {}
void Esfera::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}
void Esfera::setRadio(float r) {
	if (r<0.1F)
		r = 0.1F;
	radio = r;
}
float Esfera::getRadio() {
	return radio;
}
float Esfera::getArea() {
	return (radio*radio*PI);
}
/*void Esfera::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("C:\\Users\\user\\Documents\\UNIVERSIDAD\\Infor3o\\Juego Clase\\HeadVolley\\textures\\publicofutbol.png").id);


	glColor3ub(rojo,verde,azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}*/
void Esfera::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	sprite.draw();

	glPopMatrix();
	//glTranslatef(posicion.x, posicion.y, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("C:\\Users\\user\\Documents\\UNIVERSIDAD\\Infor3o\\Juego Clase\\HeadVolley\\textures\\publicofutbol.png").id);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("C:\\Users\\user\\Documents\\UNIVERSIDAD\\Infor3o\\Juego Clase\\HeadVolley\\textures\\publicofutbol.png").id);
	glDisable(GL_LIGHTING);
	/*
	glColor3ub(rojo, verde, azul);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glEnable(GL_LIGHTING);*/
}



void Esfera::hincha() {
	radio += 0.1;
	if (radio > 3) radio = 0.1;
}
void Esfera::control(unsigned char key){
	if (key == 'a') posicion.x -= 0.5;
	if (key == 'd') posicion.x += 0.5;
	if (key == 'w') posicion.y += 0.5;
	if (key == 's') posicion.y -= 0.5;
	if (key == '+') setRadio(radio + 0.5f);
	if (key == '-') setRadio(radio - 0.5f);
	if (key == 'r') setColor(255, 0, 0);
	if (key == 'g') setColor(0, 255, 0);
	if (key == 'b') setColor(0, 0, 255);
}
