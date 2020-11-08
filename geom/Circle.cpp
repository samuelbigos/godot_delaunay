/*
 * Circle.cpp
 *
 *  Created on: 06.03.2013
 */

#include "Circle.h"

Circle::Circle(float centerX, float centerY, float r)
{
	center = Point::create(centerX, centerY);
	radius = r;

}

Circle::~Circle( )
{
	center->dispose();
}
