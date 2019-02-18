#include "stdafx.h"
#include "ObjetoMovil.h"


ObjetoMovil::ObjetoMovil()
{
}


ObjetoMovil::~ObjetoMovil()
{
}

void ObjetoMovil::mueve(float t) {
	posicion = posicion + velocidad*t + aceleracion*0.5*t*t;
	velocidad = velocidad + aceleracion*t;
}

void ObjetoMovil::setPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

Vector2D ObjetoMovil::getPos() { return posicion; }

void ObjetoMovil::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}
void ObjetoMovil::setVel(Vector2D vel) { velocidad = vel; }
Vector2D ObjetoMovil::getVel() { return velocidad; }