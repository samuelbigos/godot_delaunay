/*
 * Circle.h
 *
 *  Created on: 06.03.2013
 */

#ifndef DELAUNAY_CIRCLE_H_
#define DELAUNAY_CIRCLE_H_

#include "Point.h"

class Circle
{
public:
	Circle(float, float, float);
	~Circle( );

	Point* center;
	float radius;
};

#endif /* DELAUNAY_CIRCLE_H_ */
