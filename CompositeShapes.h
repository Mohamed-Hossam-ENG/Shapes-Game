#pragma once
#include "Basicshapes.h"

class Sign :public shape
{
	Rect* base;
	Rect* top;
public:
	Sign(game* r_pGame, point ref);
	virtual void resize(float size);
	virtual void draw() const;
	virtual void rotate();
	void move(float X, float Y) override;
	virtual void flip();

};

class iceCream : public shape {
	circle* circ;
	fTriangle* triang;
	circle* circ1;
public:
	iceCream(game* r_pGame, point ref);
	virtual void resize(float size);
	virtual void draw()const;
	virtual void rotate();
	void move(float X, float Y) override; virtual void flip();
};

class fanoos : public shape
{
	Triangle* top;
	fTriangle* mid;
	Triangle* bottom;
public : 
	fanoos(game* r_pGame, point ref);
	virtual void resize(float size);
	virtual void draw() const;
	virtual void rotate();
	void move(float X, float Y) override; virtual void flip();
};

class House :public shape {


	Rect* down;
	Triangle* up;
	
	Triangle* t1;
public:
	House(game* r_pGame, point ref);
	virtual void resize(float size);
	virtual void draw() const;
	virtual void rotate();
	void move(float X, float Y) override; virtual void flip();

};

class Tree :public shape {


	Rect* r1;
	Triangle* t1;
	Triangle* t2;
	circle* c1;
public:
	Tree(game* r_pGame, point ref);
	virtual void resize(float size);
	virtual void flip();
	virtual void rotate();
	virtual void draw() const;
	void move(float deltaX, float deltaY) override;
};

class Car :public shape {

	Rect* rect;
	circle* cir1;
	circle* cir2;
	Triangle* t1;
public:
	Car(game* r_pGame, point ref);
	virtual void flip();
	virtual void resize(float size);
	virtual void rotate();
	virtual void draw() const;
	void move(float X, float Y) override;



};
