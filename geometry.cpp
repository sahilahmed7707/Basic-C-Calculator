#include "bits/stdc++.h"
using namespace std;

struct pt {
	int x , y , idx;
}

int dist(pt &a, pt &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int dot(pt &a, pt &b) {
	return a.x * b.x + a.y * b.y;
}

int cross(pt &a , pt &b) {
	return a.x * b.y - a.y * b.x;
}

int pointdir(pt &a , pt &b , pt &p) {

	auto sub = [&](pt & ba , pt & aa) {
		pt res;
		res.x = ba.x - aa.x;
		res.y = ba.y - aa.y;
		return res;
	}
	b = sub(b , a);
	p = sub(p , a);

	int chk = cross(b , p);
	return chk;
}

int areaTri(pt &a , pt &b , pt& c) {
	int res = cross(a , b) + cross(b , c) + cross(c , a);
	return abs(res) / 2;
}

int areaPolygon( vector<pt> &a ) {
	int n = a.size(); int res = 0;
	for (int i = 0 ; i < n ; i++)
		res += cross(a[i] , a[(i + 1) % n]);
	return abs(res) / 2;
}



int isortho(pt &a, pt &b, pt &c) {
	return (b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0;
}

//Checks if ABCD form a rectangle (in that order)
int isRectangle(pt &a, pt &b, pt &c, pt &d)
{
	return isortho(a, b, c) && isortho(b, c, d) && isortho(c, d, a);
}

//Checks if ABCD form a rectangle, in any orientation
int isRectangleAnyOrder(pt &a, pt &b, pt &c, pt &d)
{
	return isRectangle(a, b, c, d) || isRectangle(b, c, a, d) | isRectangle(c, a, b, d);
}

//Checks if ABCD form a square (in that order)
int isSquare(pt &a, pt &b, pt &c, pt &d)
{
	return isRectangle(a, b, c, d) && dist(a, b) == dist(b, c);
}

//Checks if ABCD form a square, in any orientation
int isSquareAnyOrder(pt &a, pt &b, pt &c, pt &d)
{
	return isSquare(a, b, c, d) || isSquare(b, c, a, d) | isSquare(c, a, b, d);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif

	return 0 ;
}
