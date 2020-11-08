/*
 * LineSegment.h
 *
 *  Created on: 06.03.2013
 *
 */

#ifndef DELAUNAY_LINESEGMENT_H_
#define DELAUNAY_LINESEGMENT_H_

#include "Point.h"

#include <list>


class LineSegment
{
public:
	static LineSegment* create( const Point*, const Point* );
	static void clean();
	void dispose();

	static float compareLengths_MAX(const LineSegment *, const LineSegment *);
	static float compareLengths(const LineSegment *, const LineSegment *);

	const Point* p0;
	const Point* p1;
private:
	LineSegment( const Point*, const Point* );
	~LineSegment( );
	void init( const Point*, const Point* );

	static std::list< LineSegment* > _pool;
};

#endif /* DELAUNAY_LINESEGMENT_H_ */
