#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"

#include"windows.graphics.h"
#include"CMUgraphicsLib/CMUgraphics.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

void Rect::setHeight(double newHeight)
{
	hght = newHeight;
}

void Rect::setWidth(double newWidth)
{
	wdth = newWidth;
}

double Rect::getHeight() const
{
	return hght;
}

double Rect::getWidth() const
{
	return wdth;
}


Rect::Rect(game* r_pGame, point ref, double r_hght, double r_wdth):shape(r_pGame,ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}

void Rect::move(double X, double Y)
{
	this->RefPoint.x += X;
	this->RefPoint.y += Y;
}
void Rect::resize(double n, point ref)
{
	//scale += n;
	hght = hght * (n + 1);
	wdth = wdth * (n + 1);
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

	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);

}

double circle::getRad() const
{
	return rad;
}

void circle::setRad(double newRad)
{
	rad = newRad;
}

////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, double r) :shape(r_pGame, ref) {
	rad = r;
}


void circle::resize(double n, point ref)
{
	//scale += n;
	rad = rad * (1+n);
	
}


void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);

}

void circle::move(double X, double Y)
{
	this->RefPoint.x += X;
	this->RefPoint.y += Y;
}




////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here


double Triangle::getSide() const
{
	return side;
}

void Triangle::setSide(double newSide)
{
	side = newSide;
}

Triangle::Triangle(game* r_pGame, point ref, double side) :shape(r_pGame, ref )
{

	this->side = side;
}

void Triangle::resize(double n, point ref)
{
	//scale += n;
	side = side * (n+1);
}


void Triangle::draw() const
{
	double high = (sqrt(3) / 2) * side;
	point f = { RefPoint.x, RefPoint.y - ( high / 2) };
	point s = { RefPoint.x - (side / 2), RefPoint.y + (high / 2) };
	point t = { RefPoint.x + side / 2, RefPoint.y + (high / 2) };

	window* pW = pGame->getWind();
	pW->SetPen(borderColor, config.penWidth);
	pW->DrawTriangle(f.x, f.y, s.x, s.y, t.x, t.y, FILLED);
}


void Triangle::move(double X, double Y)
{
	this->RefPoint.x += X;
	this->RefPoint.y +=Y;
}

void Triangle::rotate()
{
	rotationangle += 90.0;

	double theta = rotationangle * 3.14159265358979323846 / 180.0;


	// Calculate trigonometric functions
	double cosTheta = cos(theta);
	double sinTheta = sin(theta);
	double high = (sqrt(3) / 2) * side;
	// Define triangle vertices
	point vertices[3] = { {RefPoint.x, RefPoint.y - (high / 2)},

						  {RefPoint.x - (side / 2), RefPoint.y + (high / 2)},

						  { RefPoint.x + side / 2, RefPoint.y + (high / 2)} };

	// Rotate each vertex around the reference point
	for (int i = 0; i < 3; ++i) {
		double newX = cosTheta * (vertices[i].x - RefPoint.x) - sinTheta * (vertices[i].y - RefPoint.y) + RefPoint.x;
		double newY = sinTheta * (vertices[i].x - RefPoint.x) + cosTheta * (vertices[i].y - RefPoint.y) + RefPoint.y;

		// Update vertex coordinates
		vertices[i].x = newX;
		vertices[i].y = newY;
	}

	// Redraw the triangle with the new vertices
	window* pW = pGame->getWind();
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);

	pW->DrawTriangle(vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y, vertices[2].x, vertices[2].y, FILLED);
}


double fTriangle::getSidee() const
{
	return side;
}

void fTriangle::setSidee(double newSide)
{
	side = newSide;
}

fTriangle::fTriangle(game* r_pGame, point ref, double side) :shape(r_pGame, ref)
{
	double high = (sqrt(3) / 2) * side;

	this->side = side;
}

void fTriangle::resize(double n, point ref)
{
	//scale += n;
	side = side * (n + 1);
}

void fTriangle::draw() const
{
	double high = (sqrt(3) / 2) * side;
	point f = { RefPoint.x , RefPoint.y + (high / 2) };
	point s = { RefPoint.x - side / 2 , RefPoint.y - (high / 2) };
	point t = { RefPoint.x + side / 2 , RefPoint.y - (high / 2) };

	window* pW = pGame->getWind();
	pW->SetPen(borderColor, config.penWidth); 
	pW->DrawTriangle(f.x, f.y, s.x, s.y, t.x, t.y, FILLED);

}

void fTriangle::move(double X, double Y)
{
	this->RefPoint.x += X;
	this->RefPoint.y += Y;
}


