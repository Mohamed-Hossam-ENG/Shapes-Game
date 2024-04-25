#include "game.h"
#include "gameConfig.h"



game::game()
{
	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y) 
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{	
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}

operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op=nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this);
		printMessage("You Clicked on Create A Sign");
		break;
	case ITM_Triangle:
		op = new operAddTriangle(this);
		printMessage("You Clicked on Create A Triangle");
		break;
	case ITM_circle:
		op = new operAddcircle(this);
		printMessage("You Clicked on Create A Circle");
		break;
	case ITM_Rectangle:
		op = new operAddRectangle(this);
		printMessage("You Clicked on Create A Rectangle");
		break;
	case ITM_Save_and_Load:
		printMessage("You Cliked on Save And Load");
		break;
	case ITM_Select_GAME_LEVEl:
		printMessage("You Clicked on Select Game level");
			break;
	case ITM_Decrease:
		op = new operDecResize(this);
		printMessage("You Decreased the Size");
		break;
	case ITM_Delete:
		printMessage("You Deleted this Item");
			break;
	case ITM_Hint:
		printMessage("You Used A hint");
		break;
	case ITM_Increase:
		op = new operIncResize(this);
		printMessage("You Increased this items size");
		break;
	case ITM_Rotate:
		printMessage("You Rotated this Item");
		break;
	case ITM_Refresh:
		printMessage("You Refreshed the Game");
		break;
	case ITM_IceCream:
		printMessage("You clicked on Draw Ice Cream");
		op = new operAddIceCream(this);
		break;
	case ITM_Fanoos:
		printMessage("Ramadan kareem Kol sana w enta tyb");
		op = new operAddFanoos(this);
		break;
	case ITM_House:
		op = new operAddHouse(this);
		printMessage("You clicked on Draw House");
		break;

	case ITM_Car:
		op = new operAddCar(this);
		printMessage("You clicked on Draw car");
		break;
	case ITM_Tree:
		op = new operAddTree(this);
		printMessage("You clicked on Draw tree");
		
	}
	

	return op;
}


//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}



////////////////////////////////////////////////////////////////////////

void game::handleKeyPress(char K) {
	if (!shapesGrid || !shapesGrid->getActiveShape()) return;

	 int Step = 50; 
	shape* activeShape = shapesGrid->getActiveShape(); 
	
	switch (K) {
	case 'g': //up
		activeShape->move(0, -Step);
		break;
	case 'v'://down 
		activeShape->move(0,Step);
		break;
	case 'b': //right 
		activeShape->move(-Step, 0);
		break;
	case 'n'://left 
		activeShape->move(Step, 0);
		break;
	}

	shapesGrid->draw(); 
}

	
void game::run()
{
	int x, y;
	toolbarItem clickedItem = ITM_CNT;

	
	pWind->ChangeTitle("- - - SHAPE HUNT (CIE 101 / CIE202 - project) - - -");

	char K;
	do {
		
		while (pWind->GetKeyPress(K)) { 
			handleKeyPress(K); 
		}

		
		if (pWind->WaitMouseClick(x, y)) { 
			if (y >= 0 && y <600) {
				clickedItem = gameToolbar->getItemClicked(x);
				operation* op = createRequiredOperation(clickedItem);
				if (op) op->Act();
				shapesGrid->draw(); 
			}
		}
	} while (clickedItem != ITM_EXIT);
}
		

		