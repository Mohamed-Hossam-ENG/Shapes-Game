#include "CompositeShapes.h"
#include "gameConfig.h"
#include <cmath>

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////

Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}

void Sign::resize(double n, point ref)
{
	//config.sighShape.topHeight = config.sighShape.topHeight * (n + 1);
	//config.sighShape.baseHeight = config.sighShape.baseHeight * (n + 1);
	//config.sighShape.topWdth = config.sighShape.topWdth * (n + 1);
	//config.sighShape.baseWdth = config.sighShape.baseWdth * (n + 1);
	top->resize(n, { 0,0 });
	base->resize(n, { 0,0 });
	
	top->setRefPoint(ref);	//top rect ref is the same as the sign

	base->setRefPoint({ ref.x, ref.y + top->getHeight() / 2 + base->getHeight() / 2 });


}


void Sign::draw() const
{
	base->draw();
	top->draw();
}

iceCream::iceCream(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	point topRef = ref;
	point triRef = { ref.x , ref.y + 45 };

	circ = new circle(pGame, topRef, config.IceCream.circleRadius);
	triang = new fTriangle(pGame, triRef, config.IceCream.triangleSide + 60);

}

void iceCream::draw() const
{
	circ->draw();
	triang->draw();
}

fanoos::fanoos(game* r_pGame, point ref) : shape(r_pGame,ref)
{

	point topref = ref;
	point midref = { ref.x,ref.y + (config.fanoosShape.topside * (sqrt(3) / 2)) + (config.fanoosShape.midside * (sqrt(3) / 2)) -78 };
	point botref = { ref.x,ref.y + (config.fanoosShape.midside * (sqrt(3) / 2) + (config.fanoosShape.bottomside * (sqrt(3) / 2))) +15 };
	top = new Triangle(pGame, topref, config.fanoosShape.topside);
	mid = new fTriangle(pGame, midref, config.fanoosShape.midside);
	bottom = new Triangle(pGame, botref, config.fanoosShape.bottomside);


		
}

void fanoos::draw() const
{
	top->draw();
	mid->draw();
	bottom->draw();
}
House::House(game* r_pGame, point ref) :shape(r_pGame, ref) {

	point upref = ref;
	point downref = { ref.x, ref.y + config.sighShape.topHeight + 30 };
	up = new Triangle(pGame, upref, 100);
	down = new Rect(pGame, downref, 100, 100);

}

Tree::Tree(game* r_pGame, point ref) :shape(r_pGame, ref) {

	point trig1 = ref;
	point trig2 = { ref.x,ref.y + 40 };
	point rect = { ref.x, ref.y + config.sighShape.topHeight + 70 };

	t1 = new Triangle(pGame, trig1, 100);
	t2 = new Triangle(pGame, trig2, 100);
	r1 = new Rect(pGame, rect, 130, 30);

}

Car::Car(game* r_pGame, point ref) :shape(r_pGame, ref) {

	point up = ref;
	point cira = { ref.x - 60,ref.y + 40 };
	point cirb = { ref.x + 60,ref.y + 40 };
	rect = new Rect(pGame, ref, 50, 180);
	cir1 = new circle(pGame, cira, 20);
	cir2 = new circle(pGame, cirb, 20);



}
void House::draw() const
{
	up->draw();
	down->draw();

}
void Car::draw() const
{
	rect->draw();
	cir1->draw();
	cir2->draw();


}
void Car::move(double deltaX, double deltaY)
{
	rect->move(deltaX, deltaY);   // Assuming rect is a pointer to Rect
	cir1->move(deltaX, deltaY);   // Assuming cir1 is a pointer to Circle
	cir2->move(deltaX, deltaY);
}
void Tree::draw()const {
	t1->draw();
	t2->draw();
	r1->draw();


}



void Tree::move(double deltaX, double deltaY)
{
	t1->move( deltaX, deltaY);
	t2->move(deltaX, deltaY);
	r1->move(deltaX, deltaY);


}
