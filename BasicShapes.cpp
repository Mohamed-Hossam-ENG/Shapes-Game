#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"

#include"windows.graphics.h"
#include"CMUgraphicsLib/CMUgraphics.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

void Rect::setHeight(int newHeight)
{
	hght = newHeight;
}

void Rect::setWidth(int newWidth)
{
	wdth = newWidth;
}

int Rect::getHeight() const
{
	return hght;
}

int Rect::getWidth() const
{
	return wdth;
}


Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth):shape(r_pGame,ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}

void Rect::move(int deltaX, int deltaY)
{
	this->RefPoint.x += deltaX;
	this->RefPoint.y += deltaY;
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

int circle::getRad() const
{
	return rad;
}

void circle::setRad(int newRad)
{
	rad = newRad;
}

////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, int r) :shape(r_pGame, ref) {
	rad = r;
}


	

void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);

}

void circle::move(int deltaX, int deltaY)
{
	this->RefPoint.x += deltaX;
	this->RefPoint.y += deltaY;
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
	double high = (sqrt(3)/2) * side;
	 fx = RefPoint.x;
	 fy = RefPoint.y - (2 * high / 3);
	 sx = RefPoint.x - (side / 2);
	 sy = RefPoint.y + (high / 3);
	 tx = RefPoint.x + side / 2;
	 ty = RefPoint.y + (high / 3);
	this->side = side;
}//	 fy = RefPoint.y - (2 * high / 3);

void Triangle::draw() const
{
	window* pW = pGame->getWind();
	pW->SetPen(borderColor, config.penWidth);
	pW->DrawTriangle(fx, fy, sx, sy, tx, ty, FILLED);
}

void Triangle::move(int deltaX, int deltaY)
{
	this->RefPoint.x += deltaX;
	this->RefPoint.y += deltaY;
}

double fTriangle::getSidee() const
{
	return side;
}

void fTriangle::setSidee(double newSide)
{
	side = newSide;
}

fTriangle::fTriangle(game* r_pGame, point ref, double side): shape(r_pGame,ref)
{
	double high = (sqrt(3)/2) * side;
	fx = RefPoint.x;
	fy = RefPoint.y + (2 * high / 3);
	sx = RefPoint.x - (side / 2);
	sy = RefPoint.y - (high / 3);
	tx = RefPoint.x + side / 2;
	ty = RefPoint.y - (high / 3);
	this->side = side;
}

void fTriangle::draw() const
{
	window* pW = pGame->getWind();
	pW->SetPen(borderColor, config.penWidth);
	pW->DrawTriangle(fx, fy, sx, sy, tx, ty, FILLED);

}

void fTriangle::move(int deltaX, int deltaY)
{
	this->RefPoint.x += deltaX;
	this->RefPoint.y += deltaY;
}
