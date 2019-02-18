#pragma once
#include "Pared.h"
#include "Fondo.h"
class Caja{
private:
	Pared techo, pared_izq, pared_dcha;
	Fondo fondo;
	friend class Interaccion;
public:
	Pared suelo;
	Caja();
	~Caja();
	void dibuja();
	//Pared getCaja(char elemento[]);
};
