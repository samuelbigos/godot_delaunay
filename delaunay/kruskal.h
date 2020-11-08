/*
 * kruskal.h
 *
 *  Created on: 07.03.2013
 *
 */

#ifndef DELAUNAY_KRUSKAL_H_
#define DELAUNAY_KRUSKAL_H_

#include "../geom/LineSegment.h"

#include <vector>

enum KruskalType
{
	ktMinimum = 0, ktMaximum
};

/**
	*  Kruskal's spanning tree algorithm with union-find
	* Skiena: The Algorithm Design Manual, p. 196ff
	* Note: the sites are implied: they consist of the end points of the line segments
	*/
std::vector< LineSegment* > kruskal( std::vector< LineSegment* >& lineSegments,
		enum KruskalType type = ktMinimum );

class KruskalNode
{
public:
	KruskalNode( );

	static std::vector< KruskalNode* > pool;
	KruskalNode* parent;
	int treeSize;
};

KruskalNode* find(KruskalNode* node );

#endif /* DELAUNAY_KRUSKAL_H_ */
