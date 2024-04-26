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
	double hght, wdth;	//height and width of the recangle
public:
	void setHeight(double newHeight);
	void setWidth(double newWidth);
	double getHeight() const;
	double getWidth() const;
	Rect(game* r_pGame, point ref, double r_hght, double r_wdth);
	
	void move(double deltaX, double deltaY) override;
	void resize(double n, point ref) override;
	void draw() const override;

	void rotate() override;

};


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//Reference point of the circle is its center
class circle :public shape
{
	//Add data memebrs for class circle
	double rad;
public:	
	double getRad() const;
	void setRad(double newRad);
	circle(game* r_pGame, point ref, double r);	//add more parameters for the constructor if needed
	void resize(double n, point ref) override;
	virtual void draw() const;
	void move(double X, double Y) override;
};
class Triangle :public shape
{
	double side;
	double rotationangle;
public:
	//Triangle(game* r_pGame,int fx,int fy,int sx,int sy,int tx,int ty,double sidet);
	double getSide() const;
	void setSide(double newSide);
	Triangle(game* r_pGame, point ref, double side);
	void resize(double n, point ref) override;
	virtual void draw() const;
	void move(double X, double Y) override;

	void rotate() override;

};


class fTriangle : public shape
{

	double side;
public:
	double getSidee() const;
	void setSidee(double newSide);
	fTriangle(game* r_pGame, point ref, double side);
	void resize(double n, point ref) override;
	virtual void draw() const;
	void move(double X, double Y) override;
};