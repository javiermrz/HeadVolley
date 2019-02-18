#pragma once
#include "Vector2D.h"
class ObjetoMovil
{
protected:
	Vector2D posicion, velocidad, aceleracion;
public:
	ObjetoMovil();
	~ObjetoMovil();
	void mueve(float t);
	void setPos(float x, float y);
	Vector2D getPos();
	void setVel(float vx, float vy);
	void setVel(Vector2D vel);
	Vector2D getVel();
};

