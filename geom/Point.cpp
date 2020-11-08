/*
 * Point.cpp
 *
 *  Created on: 06.03.2013
 *
 */

#include "Point.h"

#include <math.h>

std::list<Point *> Point::_pool;
int Point::_count;

Point::Point(float X, float Y) {
	init(X, Y);
}

Point::~Point() {
	_count--;
}

void Point::init(float X, float Y) {
	x = X;
	y = Y;
}

Point *Point::create(float X, float Y) {
	Point *p = NULL;
	if (_pool.size() > 0) {
		p = _pool.front();
		_pool.pop_front();
		p->init(X, Y);
	} else {
		p = new Point(X, Y);
		_count++;
	}
	return p;
}

void Point::clean() {
	_pool.sort();
	_pool.unique();
	for (std::list<Point *>::iterator it = _pool.begin(), end = _pool.end();
			it != end; ++it) {
		delete (*it);
	}
	_pool.clear();
}

void Point::dispose() {
	_pool.push_back(this);
}

float Point::distance(const Point *v1, const Point *v2) {
	float dx = v1->x - v2->x;
	float dy = v1->y - v2->y;
	return sqrt(dx * dx + dy * dy);
}

Point *interpolate(const Point *first, const Point *second, float delta) {
	return Point::create(first->x + delta * (second->x - first->x),
			first->y + delta * (second->y - first->y));
}
