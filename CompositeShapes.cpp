#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
}
House::House(game* r_pGame, point ref) :shape(r_pGame, ref) {

	point upref = ref;
	point downref= { ref.x, ref.y + config.sighShape.topHeight+30 };
	up= new Triangle(pGame, upref, 150,1000,200,1500,250,1000,100);
	down= new Rect(pGame, downref, 100,100);

}

Tree::Tree(game* r_pGame, point ref) :shape(r_pGame, ref) {

	point trig1 = ref;
	point trig2 = { ref.x,ref.y + 40 };
	point rect = { ref.x, ref.y + config.sighShape.topHeight + 70 };

	t1 = new Triangle(pGame, trig1, 150, 600, 200, 2000, 250, 2000, 100);
	t2 = new Triangle(pGame, trig2, 150, 1000, 200, 1500, 250, 1000, 100);
	r1 = new Rect(pGame,rect ,130,30);

}









Car::Car(game* r_pGame, point ref) :shape(r_pGame, ref) {

	point up = ref;
	point cira = { ref.x - 60,ref.y + 40 };
	point cirb = { ref.x + 60,ref.y + 40 };
	rect = new Rect(pGame, ref, 50,180);
	cir1 = new circle(pGame, cira, 20);
	cir2 = new circle(pGame, cirb, 20);


}
void Sign::draw() const
{
	base->draw();
	top->draw();
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
void Tree::draw()const {
	t1->draw();
	t2->draw();
	r1->draw();


}
