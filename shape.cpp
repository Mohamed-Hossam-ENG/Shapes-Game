#include "shape.h"
#include "game.h"
#include "gameConfig.h"

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}


void shape::resize(double n, point ref)
{

}

void shape::rotate()
{

}

void shape::flip(bool set)
{
}

 void shape::move(double smallX, double smallY)
{
	RefPoint.x += smallX;
	RefPoint.y += smallY;
}


point shape:: getRefPoint() const {
	return RefPoint;
}

// Setter for the reference point
void shape:: setRefPoint(const point& newPoint) {
	RefPoint = newPoint;
}


