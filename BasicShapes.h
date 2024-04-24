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


class Rect : public shape
{
	int hght, wdth;	//height and width of the recangle
public:
	void setHeight(int newHeight);
	void setWidth(int newWidth);
	int getHeight() const;
	int getWidth() const;
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth);
	
	void move(int deltaX, int deltaY) override;
	void resize(double n) override;
	void draw() const override;

};


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//Reference point of the circle is its center
class circle :public shape
{
	//Add data memebrs for class circle
	int rad;
public:	
	int getRad() const;
	void setRad(int newRad);
	circle(game* r_pGame, point ref, int r);	//add more parameters for the constructor if needed
	void resize(double n) override;
	virtual void draw() const;
	void move(int X, int Y) override;
};
class Triangle :public shape
{
	int fx, fy;
	int sx, sy;
	int tx, ty;
	double side;
public:
	//Triangle(game* r_pGame,int fx,int fy,int sx,int sy,int tx,int ty,double sidet);
	double getSide() const;
	void setSide(double newSide);
	Triangle(game* r_pGame, point ref, double side);
	void resize(double n) override;
	virtual void draw() const;
	void move(int X, int Y) override;

};
class fTriangle : public shape
{
	int fx, fy;
	int sx, sy;
	int tx, ty;
	double side;
public:
	//Triangle(game* r_pGame,int fx,int fy,int sx,int sy,int tx,int ty,double sidet);
	double getSidee() const;
	void setSidee(double newSide);
	fTriangle(game* r_pGame, point ref, double side);
	void resize(double n) override;
	virtual void draw() const;
	void move(int X, int Y) override;
};