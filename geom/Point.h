/*
 * Point.h
 *
 *  Created on: 06.03.2013
 *
 */

#ifndef DELAUNAY_POINT_H_
#define DELAUNAY_POINT_H_

#include <list>


class Point
{
public:
	static Point *create(float, float);
	static void clean();
	void dispose();

	float x, y;

	/*
		* Returns the distance between pt1 and pt2.
		*/
	static float distance(const Point *, const Point *);
	static Point *interpolate(const Point *, const Point *, float delta);

private:
	Point(float, float);
	~Point( );
	void init(float, float);

	static std::list< Point* > _pool;
	static int _count;
};

#endif /* DELAUNAY_POINT_H_ */
