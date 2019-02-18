#include "stdafx.h"
#include "ETSIDI.h"
#include <glut.h>
#include "Interaccion.h"
#include "Mundo.h"
#include "Red.h"
#include <math.h>


Mundo::Mundo() {};
void Mundo::inicializa() {	
	setPosOjo(-3.0f, 23, 80); 

	nivel = 0;
	timer = 0;
	dif_timer = 0;

	red.setNumero(1);
	red.iniciarRed();
	red.setLimites(0, 0.0f, 13.5f, 0.0f, 0.0f);
	red.eliminarRed();
	red.disminuirRed();

	hombre1.setPos(-25, hombre1.getAltura());
	hombre1.setVel(0.0f, 0.0f);
	hombre1.setMarcador(0);
	hombre1.setToques(0);
	hombre2.setPos(25, hombre2.getAltura());
	hombre2.setVel(0.0f, 0.0f);
	hombre2.setMarcador(0);
	hombre2.setToques(0);
	
	esfera.setPos(hombre1.getPos().x, 15);
	esfera.setRadio(1.0f);
	esfera.setColor(0, 0, 50);
	esfera.setVel(0.0f, 0.0f);
	
	//GLtextura mitextura = ETSIDI::getTexture(“imágenes / fondo.png”);


}
void Mundo::iniciaPunto() {
	hombre1.setPos(-25, hombre1.getAltura());
	hombre1.setVel(0.0f, 0.0f);
	hombre1.setToques(0);
	hombre2.setPos(25, hombre2.getAltura());
	hombre2.setVel(0.0f, 0.0f);
	hombre2.setToques(0);

	esfera.setPos(hombre1.getPos().x, 15);
	esfera.setVel(0.0f, 0.0f);
}
void Mundo::setPosOjo(float x, float y, float z) {
	ojo_x = x;
	ojo_y = y;
	ojo_z = z;
}
void Mundo::dibuja() {
	
	hombre1.dibuja();
	hombre2.dibuja();
	red.dibujaRed();
	caja.dibuja();

	esfera.dibuja();
}
void Mundo::mueve() {
	timer += 0.05;
	dif_timer += 0.05;
	esfera.mueve(0.07f);
	hombre1.mueve(0.09f);
	hombre2.mueve(0.09f);
	if (comprobarBug()) a++;
	else a = 0;
	if (a > 4) iniciaPunto();
	Interaccion::rebote(hombre1, caja);
	Interaccion::rebote(hombre2, caja);
	Interaccion::rebote(esfera, hombre1.cuerpo_dcha);
	Interaccion::rebote(esfera, hombre2.cuerpo_dcha);
	if (Interaccion::rebote(hombre1, esfera)) {
		ETSIDI::play("..\\sounds\\rebote.mp3");
		hombre2.setToques(0);
		hombre1.setToques(hombre1.getToques()+1);
	}
	if (Interaccion::rebote(hombre2, esfera)) {
		ETSIDI::play("..\\sounds\\rebote.mp3");
		hombre1.setToques(0);
		hombre2.setToques(hombre2.getToques() + 1);
	}
	Interaccion::rebote(esfera, caja);
	if (Interaccion::rebote(esfera, caja.suelo)||(red.rebote(esfera)&&(esfera.getPos().y<(red.getLimite(2).y+3)))) {
		ETSIDI::play("..\\sounds\\arbitro-futbol--.mp3");
		ETSIDI::play("..\\sounds\\gol.mp3");
		if (esfera.getPos().x < 0) {
			iniciaPunto();
			hombre2.sumarMarcador();
			esfera.setPos(hombre2.getPos().x - 1.0f, hombre2.getPos().y + 15.0f);
		}
		else if (esfera.getPos().x > 0) {
			iniciaPunto();
			hombre1.sumarMarcador();
			esfera.setPos(hombre1.getPos().x + 1.0f, hombre1.getPos().y + 15.0f);
	}
	}
	if (hombre1.getToques() > 3 && hombre2.getToques() == 0) {
		iniciaPunto();
		hombre2.sumarMarcador();
		ETSIDI::play("..\\sounds\\arbitro-futbol--.mp3");
		ETSIDI::play("..\\sounds\\gol.mp3");
		esfera.setPos(hombre2.getPos().x - 1.0f, hombre2.getPos().y + 15.0f);
	}
	if (hombre2.getToques() > 3 && hombre1.getToques() == 0) {
		iniciaPunto();
		hombre1.sumarMarcador();
		ETSIDI::play("..\\sounds\\arbitro-futbol--.mp3");
		ETSIDI::play("..\\sounds\\gol.mp3");
		esfera.setPos(hombre1.getPos().x + 1.0f, hombre1.getPos().y + 15.0f);
	}

}
	void Mundo::control(unsigned char key) {
	if (key == 'p') red.disminuirRed();
	if (key == 'g') red.aumentarRed();
	//if (key == 'r') red.añadirRed();
	if (key == 'q') red.eliminarRed();
	if(key=='m')	inicializa();
	if (key == '+') esfera.setRadio(esfera.getRadio() + 0.1f);
	if (key == '-') esfera.setRadio(esfera.getRadio() - 0.1f);
	hombre2.control_jil(key);
	hombre1.control_awsd(key);
}
float Mundo::getPosOjo_x() {
	return ojo_x;
}
float Mundo::getPosOjo_y() {
	return ojo_y;
}
float Mundo::getPosOjo_z() {
	return ojo_z;
}
bool Mundo::comprobarBug() {
	if (dif_timer > 1) {
		dif_timer = 0;
		posicion_esfera2 = esfera.getPos();
		if (posicion_esfera1.x > (posicion_esfera2.x - 1.5f) && posicion_esfera1.x < (posicion_esfera2.x + 1.5f) && posicion_esfera1.y<(posicion_esfera2.y + 1.5f) && posicion_esfera1.y>(posicion_esfera2.y - 1.5f)) return true;
		else {
			posicion_esfera1 = posicion_esfera2;
			return false;
		}
	}
	return false;
}
void Mundo::getPosicionEsfera(int i) {
	switch (i) {
	case 1: posicion_esfera1 = esfera.getPos();
	case 2: posicion_esfera2 = esfera.getPos();
	}
}

int Mundo::getMarcador1() { return hombre1.getMarcador(); }
int Mundo::getMarcador2() { return hombre2.getMarcador(); }
void Mundo::contarTimer() {
	timer += 0,05;
}
float Mundo::getTimer() { return timer; }
void Mundo::cargarNivel() {
	nivel++;
	if (nivel == 1) {
		esfera.setRadio(esfera.getRadio() + 0.1f);
	}
	if (nivel == 2) {
		esfera.setRadio(esfera.getRadio() - 0.1f);
		red.aumentarRed();
	}
	if (nivel == 3) {
		red.añadirRed();
	}
}
int Mundo::getNivel() { return nivel; }