//Header file for Basic shapes in the game
#pragma once
#include "shape.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
//Rectanle class
/*							wdth
					---------------------
					|					|
			hght    |		 x			|     x is the reference point of the rectangle
					|					|
					--------------------
*/


class Rect:public shape
{
	int hght, wdth;	//height and width of the recangle
public:
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth);
	virtual void draw() const;


};


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//Reference point of the circle is its center
class circle :public shape
{
	//Add data memebrs for class circle
	int rad;
public:	
	circle(game* r_pGame, point ref, int r);	//add more parameters for the constructor if needed
	virtual void draw() const;
};
class Triangle :public shape
{
	int fx, fy;
	int sx, sy;
	int tx, ty;
	double side;
public:
	//Triangle(game* r_pGame,int fx,int fy,int sx,int sy,int tx,int ty,double sidet);
	Triangle(game* r_pGame, point ref, int fx1, int fy1, int sx2, int sy2, int tx3, int ty3, double side);
	virtual void draw() const;

};