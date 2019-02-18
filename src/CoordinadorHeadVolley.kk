//#include "ETSIDI.h"
#include "Mundo.h"

class CoordinadorHeadVolley
{
	Mundo mundo;
	enum Estado { MENU, PAUSA, JUEGO, FINAL, REGLAS };
	Estado estado;
public:
	CoordinadorHeadVolley();
	~CoordinadorHeadVolley();
	void mueve();
	void control(unsigned char key);
	void dibuja();
};

