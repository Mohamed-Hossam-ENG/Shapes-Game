#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include"shape.h"
#include <cstdlib>
#include <time.h>


grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;

	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
		delete shapeList[i];
}



void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();	
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}

//Adds a shape to the randomly created shapes list.
bool grid::addShape(shape* newShape)
{
	//TODO:
	// 1- Check that the shape can be drawn witout being clipped by grid boundaries
	// 2- check shape count doesn't exceed maximum count
	// return false if any of the checks fail
	
	//Here we assume that the above checks are passed
	shapeList[shapeCount++] = newShape;
	return true;
}

void grid::setActiveShape(shape* actShape)
{
	activeShape = actShape;
}


	
shape* grid::getActiveShape() 
{

	return activeShape;
}

shape* grid::getShapesList()
{

	return shapeList[0];
}

void grid::deleteShapesList()
{
	for (int i = 0; i < shapeCount; i++)
	{
		delete shapeList[i];
	}
}

void grid::drawAllButActiveShape() const
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
			pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);
		}
	}
	//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
	{
		if (shapeList[i])
			shapeList[i]->draw();

	}
	
}

void grid::drawAllButRandomShape() const
{
	clearGridArea(); // Clear the grid area first
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	// Draw dots showing the grid reference points
	for (int r = 1; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
		}
	}
	// Draw ALL shapes
	for (int i = 0; i < shapeCount; i++) {
		delete shapeList[i];
			 // Draw each shape
		
	}

	if (activeShape) {
		activeShape->draw();
	}
}

	
	void grid::draw() const {
		clearGridArea(); // Clear the grid area first
		window* pWind = pGame->getWind();

		pWind->SetPen(config.gridDotsColor, 1);
		pWind->SetBrush(config.gridDotsColor);

		// Draw dots showing the grid reference points
		for (int r = 1; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
			}
		}

		// Draw ALL shapes
		for (int i = 0; i < shapeCount; i++) {
			if (shapeList[i] != nullptr) {
				shapeList[i]->draw(); // Draw each shape
			}
		}

		
		if (activeShape) {
			activeShape->draw();
		}
	}
	shape* grid::DrawRandomShape()
	{
		window* pw = pGame->getWind();
		srand(time(0));
		int ct = 0;
		while (ct < pGame->getCurrentGameLevel())
		{
			int RndShape = rand() % (6);

			if (RndShape == 0)
			{
				int RndSize = rand() % 10;
				int RndRotationNo = rand() % 4;
				shape* psh = new Sign(pGame, { 500,300 });
				psh->resize(1.2);
				for (int i = 0; i < RndRotationNo; i++)
				{
					psh->rotate();
				}
				addShape(psh);
			}
			else if (RndShape == 1)
			{
				int RndSize = rand() % 10;
				int RndRotationNo = rand() % 4;
				shape* ps = new Car(pGame, { 600,300 });
				ps->resize(1.3);
				for (int i = 0; i < RndRotationNo; i++)
				{
					ps->rotate();
				}
				addShape(ps);
			}
			else if (RndShape == 2)
			{

				int RndSize = rand() % 10;
				int RndRotationNo = rand() % 4;
				shape* p = new fanoos(pGame, { 700,300 });
				p->resize(1.5);
				for (int i = 0; i < RndRotationNo; i++)
				{
					p->rotate();
				}
				addShape(p);
			}
			else if (RndShape == 3)
			{

				int RndSize = rand() % 10;
				int RndRotationNo = rand() % 4;
				shape* psh = new Tree(pGame, { 300,300 });
				psh->resize(1.7);
				for (int i = 0; i < RndRotationNo; i++)
				{
					psh->rotate();
				}
				addShape(psh);


			}
			else if (RndShape == 4)
			{
				int RndSize = rand() % 10;
				int RndRotationNo = rand() % 4;
				shape* ps = new House(pGame, { 600,300 });
				ps->resize(1.3);
				for (int i = 0; i < RndRotationNo; i++)
				{
					ps->rotate();
				}
				addShape(ps);
			}
			else if (RndShape == 5)
			{
				int RndSize = rand() % 10;
				int RndRotationNo = rand() % 4;
				shape* ps = new iceCream(pGame, { 600,300 });
				ps->resize(1.3);
				for (int i = 0; i < RndRotationNo; i++)
				{
					ps->rotate();
				}
				addShape(ps);
			}
			ct++;
		}
		return nullptr;
	}