#include "toolbar.h"
#include "game.h"
//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{	
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	toolbarItemImages[ITM_Triangle] = "images\\toolbarItems\\triangle.jpeg"; 
	toolbarItemImages[ITM_circle] = "images\\toolbarItems\\circle.jpg";
	toolbarItemImages[ITM_Rectangle] = "images\\toolbarItems\\rectangle.jpeg";
	toolbarItemImages[ITM_SIGN] = "images\\toolbarItems\\Sign.jpg";
	toolbarItemImages[ITM_IceCream] = "images\\toolbarItems\\hammer.jpg";
	toolbarItemImages[ITM_Fanoos] = "images\\toolbarItems\\Fanoos.jpg";
	toolbarItemImages[ITM_House] = "images\\toolbarItems\\house.jpg";
	toolbarItemImages[ITM_Car] = "images\\toolbarItems\\car.jpg";
	toolbarItemImages[ITM_Tree] = "images\\toolbarItems\\tree.jpg";
	toolbarItemImages[ITM_Increase] = "images\\toolbarItems\\Increase_size.jpeg";
	toolbarItemImages[ITM_Decrease] = "images\\toolbarItems\\Decrease_size.jpeg";
	toolbarItemImages[ITM_Delete] = "images\\toolbarItems\\Delete.jpeg";
	toolbarItemImages[ITM_Hint] = "images\\toolbarItems\\Hint.jpeg";
	toolbarItemImages[ITM_Rotate] = "images\\toolbarItems\\Rotate_sign.jpeg";
	toolbarItemImages[ITM_Refresh] = "images\\toolbarItems\\Refresh_Sign.jpeg";
	toolbarItemImages[ITM_Save_and_Load] = "images\\toolbarItems\\Save_and_Load.jpeg";
	toolbarItemImages[ITM_Select_GAME_LEVEl] = "images\\toolbarItems\\Game_Level.jpeg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";

	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
	{
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);
	}


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height,width , height);
}



//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{
	
	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;
	
	
	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}

