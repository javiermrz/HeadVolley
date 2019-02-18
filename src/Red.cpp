#include "stdafx.h"
#include "Red.h"


Red::Red()
{
}


Red::~Red()
{
}

bool Red::rebote(Esfera &e) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::rebote(e, *(red[i]))) return true;
	}
	return false;
}
void Red::dibujaRed() {
	for (int i = 0; i < numero; i++) red[i]->dibuja();
}	
void Red::añadirRed() {
	Pared *p = new Red();
	if (numero<2) red[numero++] = p;
	red[numero - 1]->setLimites(0.0f, 35.0f, 0.0f, 20.0f);
}
void Red::setLimites(int i, float x1, float y1, float x2, float y2) {
	red[i]->limite1.x = x1;
	red[i]->limite1.y = y1;
	red[i]->limite2.x = x2;
	red[i]->limite2.y = y2;
}
void Red::iniciarRed() {
	red[0] = new Red();
}
void Red::eliminarRed() {
	if (numero == 2)delete red[--numero];
}
void Red::aumentarRed() {
	red[0]->setLimites(0.0f, 15.0f, 0.0f, 0.0f);
}

void Red::disminuirRed() {
	red[0]->setLimites(0.0f, 13.0f, 0.0f, 0.0f);
}
void Red::setNumero(int i) {
	numero = i;
}