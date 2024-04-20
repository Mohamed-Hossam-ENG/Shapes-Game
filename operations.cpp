#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame):operation(r_pGame)
{
}
operAddTriangle::operAddTriangle(game* r_pGame):operation(r_pGame)
{
}
operAddcircle::operAddcircle(game* r_pGame) :operation(r_pGame)
{
}
operAddRectangle::operAddRectangle(game* r_pGame):operation(r_pGame)
{
}
operAddHammer::operAddHammer(game* r_pGame):operation(r_pGame)
{
}
operAddFanoos::operAddFanoos(game* r_pGame) : operation(r_pGame)
{
}
operAddHouse::operAddHouse(game* r_pGame) :operation(r_pGame)
{
}
operAddCar::operAddCar(game* r_pGame) :operation(r_pGame) 
{
}
operAddTree::operAddTree(game* r_pGame) :operation(r_pGame) 
{
}



void operAddSign::Act()
{
	window* pw = pGame->getWind();


	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };
	
	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
void operAddTriangle::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new  Triangle(pGame, signShapeRef, 80);


	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}



void operAddcircle::Act()
{
	{
		window* pw = pGame->getWind();

		//TODO:
		// Don't allow adding new shape if there is alreday an active shape

		//align reference point to the nearest grid point
		int xGrid = config.RefX - config.RefX % config.gridSpacing;
		int yGrid = config.RefY - config.RefX % config.gridSpacing;

		//take the aligned point as the sign shape ref point
		point signShapeRef = { xGrid,yGrid };


		//create a sign shape
		shape* psh = new circle(pGame, signShapeRef, 50);
		//Add the shape to the grid
		grid* pGrid = pGame->getGrid();
		pGrid->setActiveShape(psh);

	}
}
void operAddRectangle::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Rect(pGame, signShapeRef,60,50);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
void operAddHammer::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Hammer(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
void operAddFanoos::Act()
{
	window* pw = pGame->getWind();

	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	point signShapeRef = { xGrid,yGrid };
	shape* psh = new fanoos(pGame, signShapeRef);

	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

void operAddHouse::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point HouseShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new House(pGame, HouseShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

void operAddTree::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point HouseShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Tree(pGame, HouseShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


void operAddCar::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point CarShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Car(pGame, CarShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
