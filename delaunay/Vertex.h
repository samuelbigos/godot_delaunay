/*
 * Vertex.h
 *
 *  Created on: 06.03.2013
 *
 */

#ifndef DELAUNAY_VERTEX_H_
#define DELAUNAY_VERTEX_H_

#include "ICoord.h"

#include <list>

class Halfedge;

class Vertex : public ICoord
{
public:
	static void clean();

	static Vertex* create( float x, float y);
	void dispose();

	inline int vertexIndex( )
	{
		return _vertexIndex;
	}

	void setIndex();

	void out();

	/**
		* This is the only way to make a Vertex
		*
		* @param halfedge0
		* @param halfedge1
		* @return
		*
		*/
	static Vertex* intersect( Halfedge* halfedge0, Halfedge* halfedge1 );

	static Vertex* VERTEX_AT_INFINITY;

private:
	Vertex( float, float );
	~Vertex( );
	Vertex* init( float x, float y );

	static std::list< Vertex* > _pool;
	static int _nvertices;
	int _vertexIndex;
};

#endif /* DELAUNAY_VERTEX_H_ */
