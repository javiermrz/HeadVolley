#include "stdafx.h"
#include <ETSIDI.h>
#include "CoordinadorHeadVolley.h"



CoordinadorHeadVolley::CoordinadorHeadVolley()
{
	estado = MENU;
}


CoordinadorHeadVolley::~CoordinadorHeadVolley()
{
}

void CoordinadorHeadVolley::mueve() {
	if (estado == JUEGO) {
		mundo.mueve();
		if (mundo.getTimer() > 10 && mundo.getNivel() == 0) mundo.cargarNivel();
		if (mundo.getTimer() > 20 && mundo.getNivel() == 1) mundo.cargarNivel();
		if (mundo.getTimer() > 30 && mundo.getNivel() == 2) mundo.cargarNivel();
		mundo.getPosicionEsfera(1);

		//ETSIDI::playMusica(".\\sounds\\sonido estadio.mp3", false);
		if (mundo.getMarcador1() > 10) {
			estado = FINAL;
			ETSIDI::play("..\\sounds\\ole ole ole.mp3");
		}
		if (mundo.getMarcador2() > 10) {
			estado = FINAL;
			ETSIDI::play("..\\sounds\\ole ole ole.mp3");
		}
	}
}
void CoordinadorHeadVolley::control(unsigned char key) {
	if (estado == MENU) {
		if (key == 'e') {
			mundo.inicializa();
			estado = JUEGO;
		}
		else if (key == 's') exit(0);
	}
	else if (estado == JUEGO) {
		if (key == 'p') estado = PAUSA;
		if (key == 'r') estado = REGLAS;
		mundo.control(key);
	}
	else if (estado == FINAL) {
		if (key == 'e') {
			estado = JUEGO;
			mundo.inicializa();
		}
		if (key == 'm')estado = MENU;
		if (key == 's') exit(0);
	}
	else if (estado == PAUSA) {
		if (key == 'c') estado = JUEGO;
		if (key == 'r') estado = REGLAS;
		if (key == 'm') estado = MENU;
		if (key == 's') exit(0);
	}
	else if (estado == REGLAS) {
		if (key == 'c') estado = JUEGO;
	}
}
void CoordinadorHeadVolley::dibuja() {
	gluLookAt(-3.0f, 23, 80, -2, 15, 0, 0, 1, 0);
	if (estado == JUEGO) {

		mundo.dibuja();
		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::setFont("..\\fonts\\stocky.ttf", 30);
		char cadena[100];
		sprintf_s(cadena, "%i - %i", mundo.getMarcador1(), mundo.getMarcador2());
		//sprintf_s(cadena, "1");

		ETSIDI::printxy(cadena, -5, 27);
		char cadena2[100];
		sprintf_s(cadena2, "%.2f", mundo.getTimer());
		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("..\\fonts\\stocky.ttf", 16);
		ETSIDI::printxy(cadena2, 20, 32);
		ETSIDI::setTextColor(0, 0, 0);
		if (mundo.getTimer() < 10) {
			ETSIDI::printxy("R . reglas", -28, 32);
			ETSIDI::setFont("..\\fonts\\stocky.ttf", 13);
			ETSIDI::printxy("AWSD", -30, -2);
			ETSIDI::printxy("JIKL", 27, -2);
		}
	}
	else if (estado == PAUSA) {
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("..\\fonts\\stocky.ttf", 20);
		ETSIDI::printxy("PAUSA", -20, 25);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("..\\fonts\\A to Z.ttf", 12);

		ETSIDI::printxy("Pulsa c para continuar.", -17, 17);
		ETSIDI::printxy("Pulsa r para leer las reglas.", -17, 13);
		ETSIDI::printxy("Pulsa m para menu.", -17, 9);
		ETSIDI::printxy("Pulsa s para salir.", -17, 5);
	}
	else if (estado == MENU) {

		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("..\\fonts\\stocky.ttf", 30);
		ETSIDI::printxy("PANG", -20, 20);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("..\\fonts\\A to Z.ttf", 12);

		ETSIDI::printxy("Pulsa e para empezar.", -17, 10);
		ETSIDI::printxy("Pulsa s para salir.", -17, 5);
	}
	else if (estado == FINAL) {
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("..\\fonts\\stocky.ttf", 20);
		if (mundo.getMarcador1()<mundo.getMarcador2()) ETSIDI::printxy("HA GANADO EL JUGADOR 2!", -20, 20);
		else ETSIDI::printxy("HA GANADO EL JUGADOR 1!", -20, 20);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("..\\fonts\\A to Z.ttf", 12);
		ETSIDI::printxy("Pulsa e para empezar.", -17, 12);
		ETSIDI::printxy("Pulsa m para menu.", -17, 8);
		ETSIDI::printxy("Pulsa s para salir.", -17, 4);
	}
	else if (estado == REGLAS) {
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("..\\fonts\\stocky.ttf", 20);
		ETSIDI::printxy("REGLAS", -20, 30);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("..\\fonts\\A to Z.ttf", 12);

		ETSIDI::printxy("El primer jugador se mueve con awd", -17, 25);
		ETSIDI::printxy("El segundo jugador se mueve con jil", -17, 21);
		ETSIDI::printxy("La pelota puede botar contra la red o la pared", -17, 17);
		ETSIDI::printxy("No se pueden dar mas de tres toques seguidos", -17, 13);
		ETSIDI::printxy("Cada treinta segundos subira la dificultad", -17, 9);
		ETSIDI::printxy("Pulsa c para continuar", -17, 4);
	}
}