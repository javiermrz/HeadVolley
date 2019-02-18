#pragma once
#include <Vector2D.h>
#include "Esfera.h"
using namespace std;
class Pared
{
protected:
	unsigned char rojo, verde, azul;
	Vector2D limite1, limite2;
	friend class Interaccion;
	friend class Red;
public:
	Pared();
	~Pared();
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setLimites(float x1, float y1, float x2, float y2);
	Vector2D getLimite(int i);
	virtual void dibuja();
	void dibuja(int i);
	void dibujaCuerpo();
	//void dibujaFondo();
	float distancia(Vector2D punto, Vector2D *direccion = 0);
};
