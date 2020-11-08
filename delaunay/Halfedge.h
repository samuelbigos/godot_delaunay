/*
 * Halfedge.h
 *
 *  Created on: 06.03.2013
 *
 */

#ifndef DELAUNAY_HALFEDGE_H_
#define DELAUNAY_HALFEDGE_H_

#include "../geom/Point.h"
#include "Edge.h"
#include "LR.h"
#include "Vertex.h"
#include <list>

class Halfedge
{
public:
	static void clean();

	static Halfedge* create( Edge* edge, LR::Side lr );
	static Halfedge* createDummy();
	void dispose();
	void reallyDispose();

	bool isLeftOf( const Point* );

	Halfedge* edgeListLeftNeighbor;
	Halfedge* edgeListRightNeighbor;
	Halfedge* nextInPriorityQueue;

	Edge* edge;
	LR::Side leftRight;
	Vertex* vertex;

	// the vertex's y-coordinate in the transformed Voronoi space V*
	float ystar;

private:
	Halfedge( Edge* edge, LR::Side lr );
	~Halfedge( );

	static std::list< Halfedge* > _pool;

	Halfedge* init( Edge* edge, LR::Side lr );
};

#endif /* DELAUNAY_HALFEDGE_H_ */
