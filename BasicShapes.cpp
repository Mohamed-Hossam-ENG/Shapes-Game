#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"
#include <math.h>
#include"windows.graphics.h"
#include"CMUgraphicsLib/CMUgraphics.h"
#include<cmath>

point circle::pref() const { return RefPoint; }
point Rect::pref() const { return RefPoint; }
point Triangle::pref() const { return RefPoint; }
point fTriangle::pref() const { return RefPoint; }

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

void Rect::setHeight(float newHeight)
{
	hght = newHeight;
}
void Rect::setWidth(float newWidth)
{
	wdth = newWidth;
}
float Rect::getHeight() const
{
	return hght;
}
float Rect::getWidth() const
{
	return wdth;
}
void Rect::flip(){
	this->rotate(); this->rotate();
}




Rect::Rect(game* r_pGame, point ref, float r_hght, float r_wdth):shape(r_pGame,ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}
void Rect::move(float X, float Y)
{
	this->RefPoint.x += X;
	this->RefPoint.y += Y;
}
void Rect::resize(float size)
{
	hght = hght * size;
	wdth = wdth * size;
}
void Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}
void Rect::rotate() {
	window* pW = pGame->getWind();
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	int temp = hght;
	hght = wdth;
	wdth = temp;
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

}





float circle::getRad() const
{
	return rad;
}
void circle::setRad(float newRad)
{
	rad = newRad;
}
circle::circle(game* r_pGame, point ref, float r) :shape(r_pGame, ref) {
	rad = r;
}
void circle::resize(float size)
{
	rad = size * rad;
	
}
void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);

}
void circle::rotate()
{
}
void circle::move(float X, float Y)
{
	this->RefPoint.x += X;
	this->RefPoint.y += Y;
}
void circle::flip() {
	this->rotate();
}



float Triangle::getSide() const
{
	return side;
}
Triangle::Triangle(game* r_pGame, point ref, float sidee) :shape(r_pGame, ref )
{

	rotationangle = 0;
	side = sidee;
	float high = (sqrt(3) / 2) * side;
	f = { RefPoint.x, RefPoint.y - ( 2* high / 2) };
	s = { RefPoint.x - (side / 2), RefPoint.y + (high / 2) };
	t = { RefPoint.x + (side / 2), RefPoint.y + (high / 2) };
	if (rotationangle == 0) {
		f.x = RefPoint.x;
		f.y = RefPoint.y - (2 * high / 2);

		s.x = RefPoint.x - (side / 2);
		s.y = RefPoint.y + (high / 2);

		t.x = RefPoint.x + (side / 2);
		t.y = RefPoint.y + (high / 2);
	}
	else {
		for (int i = rotationangle; i > 0; i -= 90)
		{
			rotationangle -= 90;
			rotate();
		}
	}
}
void Triangle::resize(float size)
{
	side = size * side; 
}
void Triangle::draw() const
{
	window* pW = pGame->getWind();
	pW->SetPen(borderColor, config.penWidth);
	pW->DrawTriangle(f.x, f.y, s.x, s.y, t.x, t.y, FILLED);
}
void Triangle::move(float X, float Y)
{
	this->RefPoint.x += X;
	this->RefPoint.y += Y;
	float high = (sqrt(3) / 2) * side;
	if (rotationangle == 0) {
		f.x = RefPoint.x;
		f.y = RefPoint.y - (2 * high / 2);

		s.x = RefPoint.x - (side / 2);
		s.y = RefPoint.y + (high / 2);

		t.x = RefPoint.x + (side / 2);
		t.y = RefPoint.y + (high / 2);
	}
	else {
		for (int i = rotationangle; i > 0; i -= 90) {
			rotationangle -= 90;
			rotate();
		}
	}
}
void Triangle::rotate()
{
	rotationangle += 90.0;

	float theta = rotationangle * 3.14159265358979323846 / 180.0;


	// Calculate trigonometric functions
	float cosTheta = cos(theta);
	float sinTheta = sin(theta);
	float high = (sqrt(3) / 2) * side;
	// Define triangle vertices
	point vertices[3] = { {RefPoint.x, RefPoint.y - (2 * high / 2)},

						  {RefPoint.x - (side / 2), RefPoint.y + (high / 2)},

						  { RefPoint.x + (side / 2), RefPoint.y + (high / 2)} };

	// Rotate each vertex around the reference point
	for (int i = 0; i < 3; ++i) {
		double newX = cosTheta * (vertices[i].x - RefPoint.x) - sinTheta * (vertices[i].y - RefPoint.y) + RefPoint.x;
		double newY = sinTheta * (vertices[i].x - RefPoint.x) + cosTheta * (vertices[i].y - RefPoint.y) + RefPoint.y;


		// Update vertex coordinates
		vertices[i].x = newX;
		vertices[i].y = newY;
	}

	f.x = vertices[0].x;
	f.y = vertices[0].y;

	s.x = vertices[1].x;
	s.y = vertices[1].y;

	t.x = vertices[2].x;
	t.y = vertices[2].y;

}
void Triangle::flip() {
	this->rotate(); this->rotate();
}




float fTriangle::getSide() const
{
	return sideee;
}
fTriangle::fTriangle(game* r_pGame, point ref, float sidee) :shape(r_pGame, ref)
{
	rotationangle = 0;
	sideee = sidee ;
	float high = (sqrt(3) / 2) * sidee;
	f = { RefPoint.x, RefPoint.y + (2 * high / 2) };
	s = { RefPoint.x - (sideee / 2), RefPoint.y + (high / 2) };
	t = { RefPoint.x + (sideee / 2), RefPoint.y + (high / 2) };

	if (rotationangle == 0) {
		f.x = RefPoint.x;
		f.y = RefPoint.y + (high / 2);

		s.x = RefPoint.x - sideee / 2;
		s.y = RefPoint.y - (high / 2);

		t.x = RefPoint.x + sideee / 2;
		t.y = RefPoint.y - (high / 2);
	}
	else {
		for (int i = rotationangle; i > 0; i -= 90) {
			rotationangle -= 90;
			rotate();
		}
	}
}
void fTriangle::resize(float size)
{
	sideee = size * sideee; 
}
void fTriangle::move(float X, float Y)
{
	this->RefPoint.x += X;
	this->RefPoint.y += Y;
	float high = (sqrt(3) / 2) * sideee;
	if (rotationangle == 0) {
		f.x = RefPoint.x;
		f.y = RefPoint.y + (2 * high / 2);

		s.x = RefPoint.x - (sideee / 2);
		s.y = RefPoint.y - (high / 2);

		t.x = RefPoint.x + (sideee / 2);
		t.y = RefPoint.y - (high / 2);
	}
	else {
		for (int i = rotationangle; i > 0; i -= 90) {
			rotationangle -= 90;
			rotate();
		}
	}
}
void fTriangle::draw() const
{
	window* pW = pGame->getWind();
	pW->SetPen(borderColor, config.penWidth);
	pW->DrawTriangle(f.x, f.y, s.x, s.y, t.x, t.y, FILLED);

}
void fTriangle::rotate()
{
	rotationangle += 90.0;

	float theta = rotationangle * 3.14159265358979323846 / 180.0;


	// Calculate trigonometric functions
	float cosTheta = cos(theta);
	float sinTheta = sin(theta);
	float high = (sqrt(3) / 2) * sideee;
	// Define triangle vertices
	point vertices[3] = { {RefPoint.x , RefPoint.y + (high / 2)},

						  {RefPoint.x - sideee / 2 , RefPoint.y - (high / 2)},

						  { RefPoint.x + sideee / 2 , RefPoint.y - (high / 2)} };

	// Rotate each vertex around the reference point
	for (int i = 0; i < 3; ++i) {
		double newX = cosTheta * (vertices[i].x - RefPoint.x) - sinTheta * (vertices[i].y - RefPoint.y) + RefPoint.x;
		double newY = sinTheta * (vertices[i].x - RefPoint.x) + cosTheta * (vertices[i].y - RefPoint.y) + RefPoint.y;


		// Update vertex coordinates
		vertices[i].x = newX;
		vertices[i].y = newY;
	}

	f.x = vertices[0].x;
	f.y = vertices[0].y;

	s.x = vertices[1].x;
	s.y = vertices[1].y;

	t.x = vertices[2].x;
	t.y = vertices[2].y;

}
void fTriangle::flip() {
	this->rotate(); this->rotate();
}
