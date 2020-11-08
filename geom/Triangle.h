/*
 * Triangle.h
 *
 *  Created on: 06.03.2013
 */

#ifndef DELAUNAY_TRIANGLE_H_
#define DELAUNAY_TRIANGLE_H_

#include "../delaunay/Site.h"

class Triangle
{
public:
	Triangle( Site* a, Site* b , Site* c );
	Site** sites(  );

private:
	Site* _sites[3];
};

#endif /* DELAUNAY_TRIANGLE_H_ */
