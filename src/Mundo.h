#pragma once
#include "glut.h"
#include "Esfera.h"
#include "Caja.h"
#include "Hombre.h"
//#include "Bonus.h"
//#include "Disparo.h"
#include "Pared.h"
#include "Red.h"
#include "Vector2D.h"
//#include "ListaEsferas.h"

class Mundo {
	Esfera esfera;
	Caja caja;
	Hombre hombre1;
	Hombre hombre2;
	Red red;
	float timer, dif_timer;
	Vector2D posicion_esfera1, posicion_esfera2;
	friend class Interaccion;
	//Bonus bonus;
	//Disparo disparo;
	//ListaEsferas esferas;
	float ojo_x, ojo_y, ojo_z;
	float angulo=0;
	int nivel, a;
public:
	Mundo::Mundo();
	void inicializa();
	void iniciaPunto();
	void setPosOjo(float x, float y, float z);
	void dibuja();
	void mueve();
	float getPosOjo_x();
	float getPosOjo_y();
	float getPosOjo_z();
	bool comprobarBug();
	void getPosicionEsfera(int i);
	//unsigned char Tecla(unsigned char key);
	void control(unsigned char key);
	int getMarcador1();
	int getMarcador2();
	void contarTimer();
	float getTimer();
	void cargarNivel();
	int getNivel();
};
