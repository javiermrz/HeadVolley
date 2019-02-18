#include "stdafx.h"
#include "Caja.h"
#include "Pared.h"
#include <string.h>


Caja::Caja()
{
	pared_dcha.setColor(200, 200, 200);
	pared_dcha.setLimites(30, 0, 30, 35);
	pared_izq.setColor(200, 200, 200);
	pared_izq.setLimites(-30, 0, -30, 35);
	//suelo.SetColor(255, 255, 0);
	suelo.setLimites(-30, 0, 30, 0);
	techo.setColor(0, 255, 255);
	techo.setLimites(-30, 35, 30, 35);
	fondo.setColor(200, 200, 200);
	fondo.setLimites(-30, 0, 30, 35);
}


Caja::~Caja()
{
}
void Caja::dibuja() {
	suelo.dibuja(2);
	techo.dibuja();
	pared_dcha.dibuja(1);
	pared_izq.dibuja(1);
	fondo.dibuja();
}
/*Pared Caja::getCaja(char elemento[]) {
	if (strcmp(elemento, "suelo")) return suelo;	
	if (strcmp(elemento, "techo")) return techo;
	if (strcmp(elemento, "pared_dcha")) return pared_dcha;
	if (strcmp(elemento, "pared_izq")) return pared_izq;

}*/
