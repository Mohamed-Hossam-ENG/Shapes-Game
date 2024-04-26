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
	point triRef = { ref.x , ref.y + 0.5 * 3 * config.IceCream.triangleSide * (sqrt(3) / 2) * 3 / 2 };
	point top1ref = { ref.x,ref.y - config.IceCream.circleRadius };

	circ = new circle(pGame, topRef, config.IceCream.circleRadius);
	triang = new fTriangle(pGame, triRef, 3* config.IceCream.triangleSide );
	circ1 = new circle(pGame, top1ref, config.IceCream.circleRadius);
}

void iceCream::resize(double n, point ref)
{
	circ->resize(n, { 0,0 });
	triang->resize(n, { 0,0 });
	circ1->resize(n, { 0,0 });

	circ->setRefPoint (ref);
	triang->setRefPoint({ ref.x , ref.y + 0.5* triang->getSidee() * (sqrt(3) / 2) * 3/2 });
	circ1->setRefPoint({ ref.x ,ref.y - circ->getRad() });
}

void iceCream::draw() const
{
	circ->draw();
	triang->draw();
	circ1->draw();
}



void iceCream::move(double X, double Y)
{
	circ->move(X, Y);   
	triang->move(X, Y);   
	circ1->move(X, Y);
}

fanoos::fanoos(game* r_pGame, point ref) : shape(r_pGame,ref)
{

	point topref = ref;
	point midref = { ref.x,ref.y + (0.5*config.fanoosShape.topside * (sqrt(3) / 2))+ 0.5 * config.fanoosShape.midside * (sqrt(3) / 2) };
	point botref = { ref.x,ref.y + (0.5 * config.fanoosShape.topside * (sqrt(3) / 2)) + config.fanoosShape.midside * (sqrt(3) / 2) + 0.5 * config.fanoosShape.bottomside * (sqrt(3) / 2) };
	top = new Triangle(pGame, topref, config.fanoosShape.topside);
	mid = new fTriangle(pGame, midref, config.fanoosShape.midside);
	bottom = new Triangle(pGame, botref, config.fanoosShape.bottomside);

}

void fanoos::resize(double n, point ref)
{
	top->resize(n, { 0,0 });
	mid->resize(n, { 0,0 });
	bottom->resize(n, { 0,0 });

	top->setRefPoint( ref);
	mid->setRefPoint ({ ref.x,ref.y + (0.5 * top->getSide() * (sqrt(3) / 2)) + 0.5 * mid->getSidee() * (sqrt(3) / 2) });
	bottom->setRefPoint ({ ref.x,ref.y + (0.5 * top->getSide() * (sqrt(3) / 2)) + mid->getSidee() * (sqrt(3) / 2) + 0.5 * bottom->getSide() * (sqrt(3) / 2) });

}

void fanoos::draw() const
{
	top->draw();
	mid->draw();
	bottom->draw();
}
void fanoos::move(double X, double Y)
{
	top->move(X, Y);   // Assuming rect is a pointer to Rect
	mid->move(X, Y);   // Assuming cir1 is a pointer to Circle
	bottom->move(X, Y);
	
}
House::House(game* r_pGame, point ref) :shape(r_pGame, ref) {

	point upref = ref;
	point downref = { ref.x, ref.y + (0.5 * config.HouseShape.topTriangleSide * (sqrt(3) / 2)) + config.HouseShape.topTriangleSide/2 };
	point uptrig = { ref.x,ref.y - (0.3 * config.HouseShape.topTriangleSide * (sqrt(3) / 2)) };
	up = new Triangle(pGame, upref, config.HouseShape.topTriangleSide);
	down = new Rect(pGame, downref, config.HouseShape.topTriangleSide, config.HouseShape.topTriangleSide);
	t1 = new Triangle(pGame, uptrig, config.HouseShape.topTriangleSide);

	//int rectangleHeight = 130;
	//int rectangleWidth = 40;
	//int topTriangleSide = 100;
	//int bottomTriangleSide = 100;
}
void House::resize(double n, point ref)
{

	up->resize(n, { 0,0 });
	down->resize(n, { 0,0 });
	t1->resize(n, { 0,0 });

	up->setRefPoint(ref);
	down->setRefPoint({ ref.x, ref.y + (0.5 * up->getSide() * (sqrt(3) / 2)) + up->getSide() / 2 });
	t1->setRefPoint({ ref.x,ref.y - (0.3 * up->getSide() * (sqrt(3) / 2)) });


}

void House::draw() const
{
	up->draw();
	down->draw();

	t1->draw();
}
void House::move(double X, double Y)
{
	up->move(X, Y);   // Assuming rect is a pointer to Rect

	down->move(X, Y);
	t1->move(X, Y);
}

Tree::Tree(game* r_pGame, point ref) :shape(r_pGame, ref) {

	point trig1 = ref;
	point trig2 = { ref.x,ref.y + (0.5 * config.TreeShape.topTriangleSide *(sqrt(3) / 2)) };
	point rect = { ref.x, ref.y + ( config.TreeShape.topTriangleSide * (sqrt(3) / 2))  + 0.5*config.TreeShape.rectangleHeight };
	point cir = { ref.x,ref.y - (0.5 * config.TreeShape.topTriangleSide * (sqrt(3) / 2)) - config.TreeShape.circleRad };

	t1 = new Triangle(pGame, trig1, 100);
	t2 = new Triangle(pGame, trig2, 100);
	r1 = new Rect(pGame, rect, 130, 30);
	c1 = new circle(pGame, cir, config.TreeShape.circleRad);

}

void Tree::resize(double n, point ref)
{
	t1->resize(n, { 0,0 });
	t2->resize(n, { 0,0 });
	r1->resize(n, { 0,0 });
	c1->resize(n, { 0,0 });

	t1->setRefPoint(ref);
	t2->setRefPoint({ ref.x,ref.y + (0.5 * t1->getSide() * (sqrt(3) / 2)) });
	r1->setRefPoint({ ref.x, ref.y + (t1->getSide() * (sqrt(3) / 2)) + 0.5 * r1->getHeight()});
	c1->setRefPoint({ ref.x,ref.y - (0.5 * t1->getSide() * (sqrt(3) / 2)) - c1->getRad()});


}

void Tree::flip(bool set)
{
}

Car::Car(game* r_pGame, point ref) :shape(r_pGame, ref) {

	point up = ref;
	point cira = { ref.x - config.CarShape.rectanglewidth/3 , ref.y + config.CarShape.rectanglewidth/4 };
	point cirb = { ref.x + config.CarShape.rectanglewidth / 3, ref.y + config.CarShape.rectanglewidth / 4 };
	point trig = { ref.x , ref.y - (0.5 * config.CarShape.triangleside * (sqrt(3) / 2)) - config.CarShape.rectangleheight/2 };

	rect = new Rect(pGame, up, config.CarShape.rectangleheight, config.CarShape.rectanglewidth);
	cir1 = new circle(pGame, cira, config.CarShape.circletRadius);
	cir2 = new circle(pGame, cirb, config.CarShape.circletRadius);
	t1 = new Triangle(pGame, trig, config.CarShape.triangleside);


}

void Car::resize(double n, point ref)
{
	rect->resize(n, { 0,0 });
	cir1->resize(n, { 0,0 });
	cir2->resize(n, { 0,0 });
	t1->resize(n, { 0,0 });

	rect->setRefPoint(ref);
	cir1->setRefPoint({ ref.x - rect->getWidth() / 3 , ref.y + rect->getWidth() / 4 });
	cir2->setRefPoint({ ref.x + rect->getWidth() / 3, ref.y + rect->getWidth() / 4 });
	t1->setRefPoint({ ref.x , ref.y - (0.5 * t1->getSide() * (sqrt(3) / 2)) - rect->getHeight() / 2 });

}


void Car::draw() const
{
	rect->draw();
	cir1->draw();
	cir2->draw();
	t1->draw();

}

void Car::move(double X, double Y)
{
	rect->move(X, Y);   // Assuming rect is a pointer to Rect
	cir1->move(X, Y);   // Assuming cir1 is a pointer to Circle
	cir2->move(X, Y);
	t1->move(X, Y);
}
void Tree::draw()const {
	t1->draw();
	t2->draw();
	r1->draw();
	c1->draw();


}



void Tree::move(double deltaX, double deltaY)
{
	t1->move( deltaX, deltaY);
	t2->move(deltaX, deltaY);
	r1->move(deltaX, deltaY);
	c1->move(deltaX, deltaY);
}
