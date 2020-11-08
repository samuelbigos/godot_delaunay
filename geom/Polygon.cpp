/*
 * Polygon.cpp
 *
 *  Created on: 06.03.2013
 */

#include "Polygon.h"

#include <math.h>

Polygon::Polygon( std::vector<Point*>& vertices )
{
	_vertices = vertices;
}

Polygon::~Polygon( )
{
}

float Polygon::area()
{
	return fabs( signedDoubleArea() * 0.5 );
}

Winding::Direction Polygon::winding()
{
	float sDoubleArea = signedDoubleArea();
	if( sDoubleArea < 0 )
		return Winding::CLOCKWISE;
	if( sDoubleArea > 0 )
		return Winding::COUNTERCLOCKWISE;
	return Winding::NONE;
}

float Polygon::signedDoubleArea( )
{
	unsigned index, nextIndex;
	unsigned n = _vertices.size();
	Point* point;
	Point* next;
	float signedDoubleArea = 0;
	for( index = 0; index < n; ++index ){
		nextIndex = ( index + 1 ) % n;
		point = _vertices[index];
		next = _vertices[nextIndex];
		signedDoubleArea += point->x * next->y - next->x * point->y;
	}
	return signedDoubleArea;
}
