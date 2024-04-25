#pragma once
#include "Basicshapes.h"


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
//This class reprsents the composite shape "sign"
//The sign is composed of 2 Recatngles
/*				

					 ------------------
					|				   |
					|		 x		   |     x is the reference point of the Sign shape
					|			       |
					 ------------------
						   |   |
						   |   |
						   | . |
						   |   |
						   |   |
							---
*/

//Note: sign reference point is the center point of the top rectangle
class Sign :public shape
{
	Rect* base;
	Rect* top;
public:
	Sign(game* r_pGame, point ref);
	void resize(double n, point ref)override;
	virtual void draw() const;


};
class iceCream : public shape {
	circle* circ;
	fTriangle* triang;
public:
	iceCream(game* r_pGame, point ref);
	virtual void draw()const;
};

class fanoos : public shape
{
	Triangle* top;
	fTriangle* mid;
	Triangle* bottom;
public : 
	fanoos(game* r_pGame, point ref);
	virtual void draw() const;
};
class House :public shape {


	Rect* down;
	Triangle* up;
public:
	House(game* r_pGame, point ref);
	virtual void draw() const;

};
class Tree :public shape {


	Rect* r1;
	Triangle* t1;
	Triangle* t2;
public:
	Tree(game* r_pGame, point ref);
	virtual void draw() const;
	void move(double deltaX, double deltaY) override;
};
class Car :public shape {

	Rect* rect;
	circle* cir1;
	circle* cir2;
public:
	Car(game* r_pGame, point ref);

	virtual void draw() const;
	void move(double X, double Y) override;



};
