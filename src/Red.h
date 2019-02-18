#pragma once
#include "Pared.h"
#include "Interaccion.h"
class Red :
	public Pared
{
	Pared *red[2];
	int numero;
public:
	Red();
	~Red();
	bool rebote(Esfera &e);
	void setLimites(int i, float x1, float y1, float x2, float y2);
	void dibujaRed();
	void añadirRed();
	void iniciarRed();
	void eliminarRed();
	void aumentarRed();
	void disminuirRed();
	void setNumero(int i);
};

