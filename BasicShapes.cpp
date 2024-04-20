#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"

#include"windows.graphics.h"
#include"CMUgraphicsLib/CMUgraphics.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth):shape(r_pGame,ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
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




////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here


Triangle::Triangle(game* r_pGame, point ref, int fx1, int fy1, int sx2, int sy2, int tx3, int ty3, double side) :shape(r_pGame, ref )
{
	fx = fx1;
	fy = fy1;
	sx = sx2;
	sy = sy2;
	tx = tx3;
	ty = ty3;
	this->side = side;
}

void Triangle::draw() const
{
	window* pW = pGame->getWind();
	double high = (sqrt(3) / 2) * side;
	int fx = RefPoint.x;
	int fy = RefPoint.y - (2 * high / 3);
	int sx = RefPoint.x - (side / 2);
	int sy = RefPoint.y + (high / 3);
	int tx = RefPoint.x + side / 2;
	int ty = RefPoint.y + (high / 3);
	pW->SetPen(borderColor, config.penWidth);
	pW->DrawTriangle(fx, fy, sx, sy, tx, ty, FILLED);

}
