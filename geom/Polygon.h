/*
 * Polygon.h
 *
 *  Created on: 06.03.2013
 */

#ifndef DELAUNAY_POLYGON_H_
#define DELAUNAY_POLYGON_H_

#include "Point.h"

#include <vector>


namespace Winding
{
	enum Direction
	{
		NONE = 0, CLOCKWISE, COUNTERCLOCKWISE,
	};
}

class Polygon
{
public:
	Polygon( std::vector< Point* >& vertices );
	~Polygon( );
	float area( );
	Winding::Direction winding( );
	float signedDoubleArea();

private:
	std::vector< Point* > _vertices;
};

#endif /* DELAUNAY_POLYGON_H_ */
