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



 void shape::move( int deltaX, int deltaY)
{
	RefPoint.x += deltaX;
	RefPoint.y += deltaY;
}



point shape:: getRefPoint() const {
	return RefPoint;
}

// Setter for the reference point
void shape:: setRefPoint(const point& newPoint) {
	RefPoint = newPoint;
}


