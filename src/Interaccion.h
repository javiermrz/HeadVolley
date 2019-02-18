#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "Pared.h"
#include "Esfera.h"

class Interaccion
{
public:
	Interaccion();
	~Interaccion();
	static void rebote(Hombre &h, Caja c);
	static bool rebote(Hombre &h, Esfera &e);
	static bool rebote(Esfera &e, Pared p);
	static void rebote(Esfera &e, Caja &c);
	static bool rebote(Esfera &e1, Esfera &e2);


};

