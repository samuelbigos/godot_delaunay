/*
 * ICoord.h
 *
 *  Created on: 06.03.2013
 */

#ifndef DELAUNAY_ICOORD_H_
#define DELAUNAY_ICOORD_H_

#include "../geom/Point.h"

class ICoord
{
public:
	ICoord() :  _coord(NULL) {};

	inline const Point* coord( ) const
	{
		return _coord;
	}

	inline float x() const
	{
		return _coord->x;
	}
	inline float y() const
	{
		return _coord->y;
	}

	inline float dist(ICoord *p)
	{
		return Point::distance( p->coord( ), _coord );
	}

protected:
	Point* _coord;
};

#endif /* DELAUNAY_ICOORD_H_ */
