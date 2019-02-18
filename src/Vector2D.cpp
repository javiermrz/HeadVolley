#include "stdafx.h"
#include "Vector2D.h"
#include <math.h>


Vector2D::Vector2D(float xv, float yv) { 
x = xv;  
y = yv; 
}
Vector2D::~Vector2D()
{
}
Vector2D Vector2D::perpendicular()
{
	Vector2D aux;
	aux.x = y;
	aux.y = -x;
	return aux;
}
float Vector2D::modulo() { 
	return (float)sqrt(x*x + y*y); 
}
float Vector2D::argumento() { 
	return (float)atan2(y, x); 
}
Vector2D Vector2D::Unitario() {
	Vector2D retorno(x, y);  
	float mod = modulo();  
	if (mod>0.00001) {
		retorno.x /= mod;
		retorno.y /= mod;
	}  return retorno;
}
Vector2D Vector2D::operator - (Vector2D &v) { 
	Vector2D res;  
	res.x = x - v.x;  
	res.y = y - v.y;  
	return res; 
}
Vector2D Vector2D::operator + (Vector2D &v) { 
	Vector2D sum;  
	sum.x = x + v.x;  
	sum.y = y + v.y;  
	return sum; 
}
Vector2D Vector2D::operator+(float real) {
	Vector2D resultado;
	resultado.x = x + real;
	resultado.y = y + real;
	return resultado;
}
float Vector2D::operator *(Vector2D &v) {
	return(x*v.x + y*v.y);
}
Vector2D Vector2D::operator *(float num) {
	Vector2D res;
	res.x = x * num;
	res.y = y * num;
	return res;
}
Vector2D Vector2D::operator /(Vector2D &v) {
		Vector2D div;
		div.x = x/v.x;
		div.y = y/v.y;
		return div;
}
Vector2D Vector2D:: operator / (float real) {
	Vector2D div;
	div.x = x / real;
	div.y = y / real;
	return div;
}