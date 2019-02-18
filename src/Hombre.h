#pragma once
#include "ETSIDI.H"
#include "ObjetoMovil.h"
#include <Vector2D.h>
#include "Pared.h"

class Hombre: public ObjetoMovil
{
private:
	float altura, radio, ancho;
	int marcador, toques;
	friend class Interaccion;
public:
	Hombre();
	~Hombre();
	Pared cuerpo_dcha, cuerpo_izq;
	void dibuja();
	void mueve(float t);
	float getRadio();
	float getArea();
	float getAltura();
	void control_awsd(unsigned char key);
	void control_jil(unsigned char key);
	void control_Dirkeys(unsigned char key);
	void setRadio(float r);
	int getMarcador();
	void setMarcador(int i);
	void sumarMarcador();
	bool reboteCuerpo(Esfera &e);
	int getToques();
	void setToques(int t);
};

