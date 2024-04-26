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
}//	 

void Triangle::resize(double n, point ref)
{
	//scale += n;
	side = side * (n+1);
}


void Triangle::draw() const
{
	double high = (sqrt(3) / 2) * side;
	point f = { RefPoint.x, RefPoint.y - (2 * high / 3) };
	point s = { RefPoint.x - (side / 2), RefPoint.y + (high / 3) };
	point t = { RefPoint.x + side / 2, RefPoint.y + (high / 3) };

	window* pW = pGame->getWind();
	pW->SetPen(borderColor, config.penWidth);
	pW->DrawTriangle(f.x, f.y, s.x, s.y, t.x, t.y, FILLED);
}


void Triangle::move(double X, double Y)
{
	this->RefPoint.x += X;
	this->RefPoint.y +=Y;
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

void fTriangle::draw() const
{
	window* pW = pGame->getWind();
	pW->SetPen(borderColor, config.penWidth);
	int fx = RefPoint.x;
	int fy = RefPoint.y + (2 * side / 3);
	int sx = RefPoint.x - (side / 2);
	int sy = RefPoint.y - (side / 3);
	int tx = RefPoint.x + side / 2;
	int ty = RefPoint.y - (side / 3);
	pW->DrawTriangle(fx, fy, sx, sy, tx, ty, FILLED);

}

void fTriangle::move(double X, double Y)
{
	this->RefPoint.x += X;
	this->RefPoint.y += Y;
}


