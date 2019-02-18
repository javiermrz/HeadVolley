#pragma once
class Vector2D
{
public:
	float x, y;
public:
	Vector2D(float xv = 0.0f, float yv = 0.0f);
	virtual ~Vector2D();
	float modulo();
	float argumento();
	Vector2D perpendicular();
	Vector2D Unitario();
	Vector2D operator - (Vector2D &);
	Vector2D operator + (Vector2D &);	
	Vector2D operator + (float real);
	float operator *(Vector2D &);
	Vector2D operator *(float);
	Vector2D operator / (Vector2D &);
	Vector2D operator / (float real);
};


