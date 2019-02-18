#pragma once
#include "ObjetoMovil.h"
#include <Vector2D.h>
#ifndef _ESFERA_H
#define _ESFERA_H
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;
class Esfera:public ObjetoMovil {
public:
	Esfera(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
private:
	SpriteSequence sprite;
	float radio;
	unsigned char rojo, verde, azul;
	friend class Interaccion;
public:
	Esfera();
	~Esfera();
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setRadio(float r);
	float getRadio();
	float getArea();
	void dibuja();
	void hincha();
	void control(unsigned char key);
};
#endif
