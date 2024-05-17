#include "CompositeShapes.h"
#include "gameConfig.h"
#include <cmath>


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref, float rndwdth,float rndheight ,float rndwdth1 , float rndhght1):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + rndheight / 2 + rndhght1 / 2 };
	top = new Rect(pGame, topRef, rndheight, rndwdth);
	base = new Rect(pGame, baseRef, rndhght1, rndwdth1);
}
void Sign::resize(float size)
{
	point pBupdate;

	pBupdate.x = (base->pref().x - top->pref().x) * size + top->pref().x;
	pBupdate.y = (base->pref().y - top->pref().y) * size + top->pref().y;

	base->setRefPoint(pBupdate);
	top->resize(size);
	base->resize(size);
}
void Sign::rotate() {

	double cos90 = 0;
	double sin90 = 1;

	point nref;
	nref.x = (base->getRefPoint().x - top->getRefPoint().x) * cos90 - (base->getRefPoint().y - top->getRefPoint().y) * sin90 + top->getRefPoint().x;
	nref.y = (base->getRefPoint().y - top->getRefPoint().y) * cos90 + (base->getRefPoint().x - top->getRefPoint().x) * sin90 + top->getRefPoint().y;

	base->setRefPoint(nref);

	base->rotate();
	top->rotate();

}
void Sign::draw() const
{
	base->draw();
	top->draw();
}
void Sign::move(float X, float Y)
{
	base->move(X,Y);
	top->move(X,Y);
}
void Sign::flip() {
	double cos180 = -1;
	double sin180 = 0;

	point nref;
	nref.x = (base->getRefPoint().x - top->getRefPoint().x) * cos180 - (base->getRefPoint().y - top->getRefPoint().y) * sin180 + top->getRefPoint().x;
	nref.y = (base->getRefPoint().y - top->getRefPoint().y) * cos180 + (base->getRefPoint().x - top->getRefPoint().x) * sin180 + top->getRefPoint().y;

	base->setRefPoint(nref);

	base->flip();
	top->flip();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
// 
// 
////////////////////////////////////////////////////  class icecream  ///////////////////////////////////////
iceCream::iceCream(game* r_pGame, point ref,float circl , float circl1 , float ftriaingle ) : shape(r_pGame, ref)
{
	point topRef = ref;
	point triRef = { ref.x , ref.y + 0.5 * 3 * config.IceCream.triangleSide * (sqrt(3) / 2) * 3 / 2 };
	point top1ref = { ref.x,ref.y - config.IceCream.circleRadius };

	circ = new circle(pGame, topRef, circl);
	triang = new fTriangle(pGame, triRef, 3* ftriaingle);
	circ1 = new circle(pGame, top1ref, circl1);
}
void iceCream::resize(float size)
{
	circ->resize(size);
	circ1->resize(size);

	point nc, tri;
	tri = { ((triang->pref().x - circ->pref().x) * size + circ->pref().x), ((triang->pref().y - circ->pref().y) * size + circ->pref().y) };
	nc = nc = { ((circ1->pref().x - circ->pref().x) * size + circ->pref().x), ((circ1->pref().y - circ->pref().y) * size + circ->pref().y) };
	circ1->setRefPoint(nc);
	triang->setRefPoint(tri);
	triang->resize(size);
	triang->rotate(), triang->rotate(), triang->rotate(), triang->rotate();
}
void iceCream::draw() const
{
	circ->draw();
	triang->draw();
	circ1->draw();
}
void iceCream::move(float X, float Y)
{
	circ->move(X, Y);
	triang->move(X, Y);
	circ1->move(X, Y);
}
void iceCream::rotate()
{
	int cos90 = 0;
	int sin90 = 1;

	point nref1, nref2;
	nref1.x = (circ1->getRefPoint().x - circ->getRefPoint().x) * cos90 - (circ1->getRefPoint().y - circ->getRefPoint().y) * sin90 + circ->getRefPoint().x;
	nref1.y = (circ1->getRefPoint().y - circ->getRefPoint().y) * cos90 + (circ1->getRefPoint().x - circ->getRefPoint().x) * sin90 + circ->getRefPoint().y;

	nref2.x = (triang->getRefPoint().x - circ->getRefPoint().x) * cos90 - (triang->getRefPoint().y - circ->getRefPoint().y) * sin90 + circ->getRefPoint().x;
	nref2.y = (triang->getRefPoint().y - circ->getRefPoint().y) * cos90 + (triang->getRefPoint().x - circ->getRefPoint().x) * sin90 + circ->getRefPoint().y;


	circ1->setRefPoint(nref1);
	triang->setRefPoint(nref2);


	circ->draw();
	circ1->draw();
	triang->rotate();
}
void iceCream::flip() {
	double cos180 = -1;
	double sin180 = 0;

	point nref1, nref2;
	nref1.x = (circ1->getRefPoint().x - circ->getRefPoint().x) * cos180 - (circ1->getRefPoint().y - circ->getRefPoint().y) * sin180 + circ->getRefPoint().x;
	nref1.y = (circ1->getRefPoint().y - circ->getRefPoint().y) * cos180 + (circ1->getRefPoint().x - circ->getRefPoint().x) * sin180 + circ->getRefPoint().y;

	nref2.x = (triang->getRefPoint().x - circ->getRefPoint().x) * cos180 - (triang->getRefPoint().y - circ->getRefPoint().y) * sin180 + circ->getRefPoint().x;
	nref2.y = (triang->getRefPoint().y - circ->getRefPoint().y) * cos180 + (triang->getRefPoint().x - circ->getRefPoint().x) * sin180 + circ->getRefPoint().y;


	circ1->setRefPoint(nref1);
	triang->setRefPoint(nref2);


	circ->draw();
	circ1->draw();
	triang->flip();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
// 
// 
////////////////////////////////////////////////////  class fanoos  ///////////////////////////////////////
void fanoos::rotate() {

	double cos90 = 0;
	double sin90 = 1;
	point nref1, nref2;

	nref1.x = (mid->getRefPoint().x - top->getRefPoint().x) * cos90 - (mid->getRefPoint().y - top->getRefPoint().y) * sin90 + top->getRefPoint().x;

	nref1.y = (mid->getRefPoint().y - top->getRefPoint().y) * cos90 + (mid->getRefPoint().x - top->getRefPoint().x) * sin90 + top->getRefPoint().y;

	nref2.x = (bottom->getRefPoint().x - top->getRefPoint().x) * cos90 - (bottom->getRefPoint().y - top->getRefPoint().y) * sin90 + top->getRefPoint().x;

	nref2.y = (bottom->getRefPoint().y - top->getRefPoint().y) * cos90 + (bottom->getRefPoint().x - top->getRefPoint().x) * sin90 + top->getRefPoint().y;

	bottom->setRefPoint(nref2);
	mid->setRefPoint(nref1);

	top->rotate();
	mid->rotate();
	bottom->rotate();
}
fanoos::fanoos(game* r_pGame, point ref,float side1, float side2 , float side3) : shape(r_pGame,ref)
{

	point topref = ref;
	point midref = { ref.x,ref.y + (0.5*config.fanoosShape.topside * (sqrt(3) / 2))+ 0.5 * config.fanoosShape.midside * (sqrt(3) / 2) };
	point botref = { ref.x,ref.y + (0.5 * config.fanoosShape.topside * (sqrt(3) / 2)) + config.fanoosShape.midside * (sqrt(3) / 2) + 0.5 * config.fanoosShape.bottomside * (sqrt(3) / 2) };
	top = new Triangle(pGame, topref, side1);
	mid = new fTriangle(pGame, midref, side2);
	bottom = new Triangle(pGame, botref, side3);

}
void fanoos::draw() const
{
	top->draw();
	mid->draw();
	bottom->draw();
}
void fanoos::resize(float size)
{
	mid->resize(size);
	bottom->resize(size);
	top->resize(size);

	point rmid, rbot;
	rmid  = { ((mid->pref().x - top->pref().x) * size + top->pref().x), ((mid->pref().y - top->pref().y) * size + top->pref().y) };
	rbot = { ((bottom->pref().x - top->pref().x) * size + top->pref().x), ((bottom->pref().y - top->pref().y) * size + top->pref().y) };
	mid->setRefPoint(rmid);
	bottom->setRefPoint(rbot);

	mid->rotate();
	bottom->rotate();
	top->rotate();
	mid->rotate();
	bottom->rotate();
	top->rotate();
	mid->rotate();
	bottom->rotate();
	top->rotate();
	mid->rotate();
	bottom->rotate();
	top->rotate();
	
}
void fanoos::move(float X, float Y)
{
	top->move(X, Y);   // Assuming rect is a pointer to Rect
	mid->move(X, Y);   // Assuming cir1 is a pointer to Circle
	bottom->move(X, Y);
	
}
void fanoos::flip() {
	double cos180 = -1;
	double sin180 = 0;
	point nref1, nref2;

	nref1.x = (mid->getRefPoint().x - top->getRefPoint().x) * cos180 - (mid->getRefPoint().y - top->getRefPoint().y) * sin180 + top->getRefPoint().x;

	nref1.y = (mid->getRefPoint().y - top->getRefPoint().y) * cos180 + (mid->getRefPoint().x - top->getRefPoint().x) * sin180 + top->getRefPoint().y;

	nref2.x = (bottom->getRefPoint().x - top->getRefPoint().x) * cos180 - (bottom->getRefPoint().y - top->getRefPoint().y) * sin180 + top->getRefPoint().x;

	nref2.y = (bottom->getRefPoint().y - top->getRefPoint().y) * cos180 + (bottom->getRefPoint().x - top->getRefPoint().x) * sin180 + top->getRefPoint().y;

	bottom->setRefPoint(nref2);
	mid->setRefPoint(nref1);

	top->flip();
	mid->flip();
	bottom->flip();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
// 
// 
////////////////////////////////////////////////////  class house  ///////////////////////////////////////
House::House(game* r_pGame, point ref, float rectwidth , float rectheight , float traingle1  , float triangle2 ) :shape(r_pGame, ref) {

	point upref = ref;
	point downref = { ref.x, ref.y + (0.5 * config.HouseShape.topTriangleSide * (sqrt(3) / 2)) + config.HouseShape.topTriangleSide/2 };
	point uptrig = { ref.x,ref.y - (0.3 * config.HouseShape.topTriangleSide * (sqrt(3) / 2)) };
	up = new Triangle(pGame, upref,traingle1);
	down = new Rect(pGame, downref, rectwidth,rectheight);
	t1 = new Triangle(pGame, uptrig, triangle2);

}
void House::resize(float size)
{
	up->resize(size);
	down->resize(size);
	t1->resize(size);
	point downn, tr;
	downn.x = (down->pref().x - up->pref().x) * size + up->pref().x;
	downn.y = (down->pref().y - up->pref().y) * size + up->pref().y;
	tr.x = (t1->pref().x - up->pref().x) * size + up->pref().x;
	tr.y = (t1->pref().y - up->pref().y) * size + up->pref().y;

	down->setRefPoint(downn);
	t1->setRefPoint(tr);

	up->rotate(); up->rotate(); up->rotate(); up->rotate();
	t1->rotate(); t1->rotate(); t1->rotate(); t1->rotate();
}
void House::rotate()
{

	double cos90 = 0;
	double sin90 = 1;

	point nref, nref1;
	nref.x = (up->getRefPoint().x - down->getRefPoint().x) * cos90 - (up->getRefPoint().y - down->getRefPoint().y) * sin90 + down->getRefPoint().x;
	nref.y = (up->getRefPoint().y - down->getRefPoint().y) * cos90 + (up->getRefPoint().x - down->getRefPoint().x) * sin90 + down->getRefPoint().y;

	nref1.x = (t1->getRefPoint().x - down->getRefPoint().x) * cos90 - (t1->getRefPoint().y - down->getRefPoint().y) * sin90 + down->getRefPoint().x;
	nref1.y = (t1->getRefPoint().y - down->getRefPoint().y) * cos90 + (t1->getRefPoint().x - down->getRefPoint().x) * sin90 + down->getRefPoint().y;

	up->setRefPoint(nref);
	t1->setRefPoint(nref1);

	t1->rotate();
	up->rotate();
	down->rotate();

}
void House::draw() const
{
	up->draw();
	down->draw();
	t1->draw();
}
void House::move(float X, float Y)
{
	up->move(X, Y);   // Assuming rect is a pointer to Rect

	down->move(X, Y);
	t1->move(X, Y);
}
void House::flip() {

	double cos180 = -1;
	double sin180 = 0;

	point nref, nref1;
	nref.x = (up->getRefPoint().x - down->getRefPoint().x) * cos180 - (up->getRefPoint().y - down->getRefPoint().y) * sin180 + down->getRefPoint().x;
	nref.y = (up->getRefPoint().y - down->getRefPoint().y) * cos180 + (up->getRefPoint().x - down->getRefPoint().x) * sin180 + down->getRefPoint().y;

	nref1.x = (t1->getRefPoint().x - down->getRefPoint().x) * cos180 - (t1->getRefPoint().y - down->getRefPoint().y) * sin180 + down->getRefPoint().x;
	nref1.y = (t1->getRefPoint().y - down->getRefPoint().y) * cos180 + (t1->getRefPoint().x - down->getRefPoint().x) * sin180 + down->getRefPoint().y;

	up->setRefPoint(nref);
	t1->setRefPoint(nref1);

	t1->flip();
	up->flip();
	down->flip();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
// 
// 
////////////////////////////////////////////////////  class car  ///////////////////////////////////////
Car::Car(game* r_pGame, point ref, float sidee , float radius , float length , float widht ) :shape(r_pGame, ref) {

	point up = ref;
	point cira = { ref.x - config.CarShape.rectanglewidth/3 , ref.y + config.CarShape.rectanglewidth/4 };
	point cirb = { ref.x + config.CarShape.rectanglewidth / 3, ref.y + config.CarShape.rectanglewidth / 4 };
	point trig = { ref.x , ref.y - (0.5 * config.CarShape.triangleside * (sqrt(3) / 2)) - config.CarShape.rectangleheight/2 };

	rect = new Rect(pGame, up, length, widht);
	cir1 = new circle(pGame, cira, radius);
	cir2 = new circle(pGame, cirb, radius);
	t1 = new Triangle(pGame, trig, sidee);


}
void Car::resize(float size)
{
	point cira, cirb, trig;
	cira = { ((cir1->pref().x - rect->pref().x) * size + rect->pref().x), ((cir1->pref().y - rect->pref().y) * size + rect->pref().y) };
	cirb = { ((cir2->pref().x - rect->pref().x) * size + rect->pref().x), ((cir2->pref().y - rect->pref().y) * size + rect->pref().y) };
	trig = { ((t1->pref().x - rect->pref().x) * size + rect->pref().x), ((t1->pref().y - rect->pref().y) * size + rect->pref().y) };

	cir1->setRefPoint(cira);
	cir2->setRefPoint(cirb);
	t1->setRefPoint(trig);
	cir1->resize(size);
	cir2->resize(size);
	t1->resize(size);
	t1->rotate();
	t1->rotate();
	t1->rotate();
	t1->rotate();
	rect->resize(size);

}
void Car::draw() const
{
	rect->draw();
	cir1->draw();
	cir2->draw();
	t1->draw();

}
void Car::move(float X, float Y)
{
	rect->move(X, Y);   // Assuming rect is a pointer to Rect
	cir1->move(X, Y);   // Assuming cir1 is a pointer to Circle
	cir2->move(X, Y);
	t1->move(X, Y);
}
void Car::rotate()
{

	double cos90 = 0;
	double sin90 = 1;

	point nref1, nref2, nref3;
	nref1.x = (cir1->getRefPoint().x - rect->getRefPoint().x) * cos90 - (cir1->getRefPoint().y - rect->getRefPoint().y) * sin90 + rect->getRefPoint().x;
	nref1.y = (cir1->getRefPoint().y - rect->getRefPoint().y) * cos90 + (cir1->getRefPoint().x - rect->getRefPoint().x) * sin90 + rect->getRefPoint().y;

	nref2.x = (cir2->getRefPoint().x - rect->getRefPoint().x) * cos90 - (cir2->getRefPoint().y - rect->getRefPoint().y) * sin90 + rect->getRefPoint().x;
	nref2.y = (cir2->getRefPoint().y - rect->getRefPoint().y) * cos90 + (cir2->getRefPoint().x - rect->getRefPoint().x) * sin90 + rect->getRefPoint().y;

	nref3.x = (t1->getRefPoint().x - rect->getRefPoint().x) * cos90 - (t1->getRefPoint().y - rect->getRefPoint().y) * sin90 + rect->getRefPoint().x;
	nref3.y = (t1->getRefPoint().y - rect->getRefPoint().y) * cos90 + (t1->getRefPoint().x - rect->getRefPoint().x) * sin90 + rect->getRefPoint().y;


	cir1->setRefPoint(nref1);
	cir2->setRefPoint(nref2);
	t1->setRefPoint(nref3);

	t1->rotate();
	rect->rotate();
	cir1->draw();
	cir2->draw();

}
void Car::flip() {
	double cos180 = -1;
	double sin180 = 0;

	point nref1, nref2, nref3;
	nref1.x = (cir1->getRefPoint().x - rect->getRefPoint().x) * cos180 - (cir1->getRefPoint().y - rect->getRefPoint().y) * sin180 + rect->getRefPoint().x;
	nref1.y = (cir1->getRefPoint().y - rect->getRefPoint().y) * cos180 + (cir1->getRefPoint().x - rect->getRefPoint().x) * sin180 + rect->getRefPoint().y;

	nref2.x = (cir2->getRefPoint().x - rect->getRefPoint().x) * cos180 - (cir2->getRefPoint().y - rect->getRefPoint().y) * sin180 + rect->getRefPoint().x;
	nref2.y = (cir2->getRefPoint().y - rect->getRefPoint().y) * cos180 + (cir2->getRefPoint().x - rect->getRefPoint().x) * sin180 + rect->getRefPoint().y;

	nref3.x = (t1->getRefPoint().x - rect->getRefPoint().x) * cos180 - (t1->getRefPoint().y - rect->getRefPoint().y) * sin180 + rect->getRefPoint().x;
	nref3.y = (t1->getRefPoint().y - rect->getRefPoint().y) * cos180 + (t1->getRefPoint().x - rect->getRefPoint().x) * sin180 + rect->getRefPoint().y;


	cir1->setRefPoint(nref1);
	cir2->setRefPoint(nref2);
	t1->setRefPoint(nref3);

	t1->flip();
	rect->flip();
	cir1->draw();
	cir2->draw();

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
// 
// 
////////////////////////////////////////////////////  class tree  ///////////////////////////////////////
Tree::Tree(game* r_pGame, point ref, float rectWidth, float rectheight, float triangle1, float trianlge2, float circlerad ) :shape(r_pGame, ref) {

	point trig1 = ref;
	point trig2 = { ref.x,ref.y + (0.5 * config.TreeShape.topTriangleSide * (sqrt(3) / 2)) };
	point rect = { ref.x, ref.y + (config.TreeShape.topTriangleSide * (sqrt(3) / 2)) + 0.5 * config.TreeShape.rectangleHeight };
	point cir = { ref.x,ref.y - (config.TreeShape.topTriangleSide * (sqrt(3) / 2)) - config.TreeShape.circleRad };

	t1 = new Triangle(pGame, trig1, triangle1);
	t2 = new Triangle(pGame, trig2, trianlge2);
	r1 = new Rect(pGame, rect, rectWidth, rectheight);
	c1 = new circle(pGame, cir, circlerad);

}
void Tree::resize(float size)
{
	t1->resize(size);
	t2->resize(size);
	r1->resize(size);
	c1->resize(size);
	point pt, pr, pc;

	pt.x = (t2->pref().x - t1->pref().x) * size + t1->pref().x;
	pt.y = (t2->pref().y - t1->pref().y) * size + t1->pref().y;

	pr.x = (r1->pref().x - t1->pref().x) * size + t1->pref().x;
	pr.y = (r1->pref().y - t1->pref().y) * size + t1->pref().y;

	pc.x = (c1->pref().x - t1->pref().x) * size + t1->pref().x;
	pc.y = (c1->pref().y - t1->pref().y) * size + t1->pref().y;

	t2->setRefPoint(pt), r1->setRefPoint(pr), c1->setRefPoint(pc);
	t2->rotate(),t2->rotate(), t2->rotate(), t2->rotate();
	t1->rotate(), t1->rotate(), t1->rotate(), t1->rotate();
}
void Tree::rotate() {


	double cos90 = 0;
	double sin90 = 1;

	point nref1, nref2, nref3;
	nref1.x = (t1->getRefPoint().x - r1->getRefPoint().x) * cos90 - (t1->getRefPoint().y - r1->getRefPoint().y) * sin90 + r1->getRefPoint().x;
	nref1.y = (t1->getRefPoint().y - r1->getRefPoint().y) * cos90 + (t1->getRefPoint().x - r1->getRefPoint().x) * sin90 + r1->getRefPoint().y;

	nref2.x = (t2->getRefPoint().x - r1->getRefPoint().x) * cos90 - (t2->getRefPoint().y - r1->getRefPoint().y) * sin90 + r1->getRefPoint().x;
	nref2.y = (t2->getRefPoint().y - r1->getRefPoint().y) * cos90 + (t2->getRefPoint().x - r1->getRefPoint().x) * sin90 + r1->getRefPoint().y;

	nref3.x = (c1->getRefPoint().x - r1->getRefPoint().x) * cos90 - (c1->getRefPoint().y - r1->getRefPoint().y) * sin90 + r1->getRefPoint().x;
	nref3.y = (c1->getRefPoint().y - r1->getRefPoint().y) * cos90 + (c1->getRefPoint().x - r1->getRefPoint().x) * sin90 + r1->getRefPoint().y;


	t1->setRefPoint(nref1);
	t2->setRefPoint(nref2);
	c1->setRefPoint(nref3);

	c1->draw();
	t1->rotate();
	t2->rotate();
	r1->rotate();
}
void Tree::draw()const {
	t1->draw();
	t2->draw();
	r1->draw();
	c1->draw();
}
void Tree::move(float deltaX, float deltaY)
{
	t1->move( deltaX, deltaY);
	t2->move(deltaX, deltaY);
	r1->move(deltaX, deltaY);
	c1->move(deltaX, deltaY);
}
void Tree::flip()
{
	double cos180 = -1;
	double sin180 = 0;

	point nref1, nref2, nref3;
	nref1.x = (t1->getRefPoint().x - r1->getRefPoint().x) * cos180 - (t1->getRefPoint().y - r1->getRefPoint().y) * sin180 + r1->getRefPoint().x;
	nref1.y = (t1->getRefPoint().y - r1->getRefPoint().y) * cos180 + (t1->getRefPoint().x - r1->getRefPoint().x) * sin180 + r1->getRefPoint().y;

	nref2.x = (t2->getRefPoint().x - r1->getRefPoint().x) * cos180 - (t2->getRefPoint().y - r1->getRefPoint().y) * sin180 + r1->getRefPoint().x;
	nref2.y = (t2->getRefPoint().y - r1->getRefPoint().y) * cos180 + (t2->getRefPoint().x - r1->getRefPoint().x) * sin180 + r1->getRefPoint().y;

	nref3.x = (c1->getRefPoint().x - r1->getRefPoint().x) * cos180 - (c1->getRefPoint().y - r1->getRefPoint().y) * sin180 + r1->getRefPoint().x;
	nref3.y = (c1->getRefPoint().y - r1->getRefPoint().y) * cos180 + (c1->getRefPoint().x - r1->getRefPoint().x) * sin180 + r1->getRefPoint().y;


	t1->setRefPoint(nref1);
	t2->setRefPoint(nref2);
	c1->setRefPoint(nref3);

	c1->draw();
	t1->flip();
	t2->flip();
	r1->flip();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////