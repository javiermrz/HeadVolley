#include "stdafx.h"
#include "Interaccion.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Mundo.h"


Interaccion::Interaccion()
{
}


Interaccion::~Interaccion()
{
}

void Interaccion::rebote(Hombre &h, Caja c)
{
	float xmax = c.suelo.limite2.x;
	float xmin = c.suelo.limite1.x;
	float y = c.suelo.limite1.y;
	if (h.posicion.x>xmax)h.posicion.x = xmax;
	if (h.posicion.x<xmin)h.posicion.x = xmin;
	if (h.posicion.y<(y+h.radio+h.altura))h.posicion.y = (y+h.radio+h.altura);
	
	if (((h.posicion.x - h.radio) < 0) && (h.posicion.x> 0)) {
		h.velocidad.x = 0;
		h.posicion.x = h.radio + 0.01;
	}
	if (((h.posicion.x + h.radio) > 0) && (h.posicion.x < 0)) {
		h.velocidad.x = 0;
		h.posicion.x = -h.radio - 0.01;
	}
}
bool Interaccion::rebote(Esfera &e, Pared p)
{
	Vector2D dir;
	Vector2D pos_previa;
	float dif = p.distancia(e.posicion, &dir) - e.radio;
	//if (dif <= 2.0f && dif>=0.9f) pos_previa = e.posicion;
	if (dif <= 0.2f)
	{
		pos_previa = e.posicion;
		Vector2D v_inicial = e.velocidad;
		e.velocidad = (v_inicial - dir*2.0*(v_inicial*dir))*0.95;
		//e.posicion = e.posicion - (dir*dif*1.75f);
		e.posicion = pos_previa;
		return true;
	}
	return false;
}
void Interaccion::rebote(Esfera &e, Caja &c) {
	rebote(e, c.pared_dcha);
	//rebote(e, c.suelo);
	rebote(e, c.pared_izq);
	rebote(e, c.techo);
}
bool Interaccion::rebote(Esfera &e1, Esfera &e2)
{
	Vector2D dist = e1.posicion - e2.posicion;
	float r = 4;
	float rads = e1.getRadio() + e2.getRadio();
	if (dist.modulo() <= rads+0.1f) {
		e1.setRadio(++r);
		Vector2D vel1_aux = e1.velocidad;
		Vector2D vel2_aux = e2.velocidad;
		e1.velocidad = vel2_aux*(e2.getArea() * 2 / (e1.getArea() + e2.getArea())) + (vel1_aux*(e1.getArea() - e2.getArea()) / (e1.getArea() + e2.getArea()));
		e2.velocidad = vel1_aux*(e1.getArea() * 2 / (e1.getArea() + e2.getArea())) + (vel2_aux*(e2.getArea() - e1.getArea()) / (e1.getArea() + e2.getArea()));
		return true;
	} 
	return false;
}
bool Interaccion::rebote(Hombre &h, Esfera &e)
{
	Vector2D dist = h.posicion - e.posicion;
	Vector2D pos_previa;
	float area_hombre = h.getArea();
	float area_esfera = e.getArea();
	float rads = h.getRadio() + e.getRadio();
	if (dist.modulo() <= rads + 0.2f) pos_previa = e.posicion;
	if (dist.modulo() <= rads+0.1f) {
	
		Vector2D vel1_aux = h.velocidad;
		Vector2D vel2_aux = e.velocidad;
		if (h.velocidad.y > 0.5f&& e.velocidad.y<=0) {
			e.velocidad = vel1_aux*(area_hombre * 2 / (area_hombre + area_esfera)) + (vel2_aux*(area_esfera - area_hombre) / (area_hombre + area_esfera));
			h.velocidad = vel2_aux*(area_esfera * 2 / (area_hombre + area_esfera)) + (vel1_aux*(area_hombre - area_esfera) / (area_hombre + area_esfera));
			//e.posicion = e.posicion - dist;
			e.posicion = pos_previa;
		}
		else e.velocidad.y = vel2_aux.y - vel2_aux.y * 2;
 // if (!h.SetVel((h.GetPos() - e.GetPos()).perpendicular()))
	//e.SetVel((h.GetPos() - e.GetPos()).perpendicular());
		return true;
	}
	return false;
}