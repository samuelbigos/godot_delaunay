/*
 * kruskal.cpp
 *
 *  Created on: 07.03.2013
 *
 */

#include "kruskal.h"
#include "../geom/Point.h"

#include <map>
#include <algorithm>

std::vector< KruskalNode* > KruskalNode::pool;

std::vector< LineSegment* > kruskal( std::vector< LineSegment* >& lineSegments,
		enum KruskalType type )
{
	std::map< const Point*, KruskalNode* > nodes;
	std::vector< LineSegment* > mst;
	std::vector< KruskalNode* > nodePool = KruskalNode::pool;
	switch( type ){
		// note that the compare functions are the reverse of what you'd expect
		// because (see below) we traverse the lineSegments in reverse order for speed
		case ktMaximum:
			std::sort( lineSegments.begin( ), lineSegments.end( ),
					LineSegment::compareLengths );
			break;
		default:
			std::sort( lineSegments.begin( ), lineSegments.end( ),
					LineSegment::compareLengths_MAX );
			break;
	}

	for( int i = lineSegments.size( ); --i > -1; ){
		LineSegment* lineSegment = lineSegments[i];
		KruskalNode* node0 = nodes[lineSegment->p0];
		KruskalNode* rootOfSet0 = NULL;
		if( node0 == NULL ){
			if( nodePool.size( ) > 0 ){
				node0 = nodePool.back( );
				nodePool.pop_back( );
			}else{
				node0 = new KruskalNode( );
			}
			// intialize the node:
			rootOfSet0 = node0->parent = node0;
			node0->treeSize = 1;

			nodes[lineSegment->p0] = node0;
		}else{
			rootOfSet0 = find( node0 );
		}

		KruskalNode* node1 = nodes[lineSegment->p1];
		KruskalNode* rootOfSet1;
		if( node1 == NULL ){
			if( nodePool.size( ) > 0 ){
				node1 = nodePool.back( );
				nodePool.pop_back( );
			}else{
				node1 = new KruskalNode( );
			}

			// intialize the node:
			rootOfSet1 = node1->parent = node1;
			node1->treeSize = 1;

			nodes[lineSegment->p1] = node1;
		}else{
			rootOfSet1 = find( node1 );
		}

		if( rootOfSet0 != rootOfSet1 ){	// nodes not in same set
			mst.push_back( lineSegment );

			// merge the two sets:
			int treeSize0 = rootOfSet0->treeSize;
			int treeSize1 = rootOfSet1->treeSize;
			if( treeSize0 >= treeSize1 ){
				// set0 absorbs set1:
				rootOfSet1->parent = rootOfSet0;
				rootOfSet0->treeSize += treeSize1;
			}else{
				// set1 absorbs set0:
				rootOfSet0->parent = rootOfSet1;
				rootOfSet1->treeSize += treeSize0;
			}
		}
	}

	for( std::map< const Point*, KruskalNode* >::iterator it = nodes.begin( );
			it != nodes.end( ); ++it ){
		nodePool.push_back( it->second );
	}

	return mst;
}

KruskalNode::KruskalNode( ) : parent(NULL), treeSize(0)
{

}

KruskalNode* find(KruskalNode* node )
{
	if( node->parent == node ){
		return node;
	}else{
		KruskalNode* root = find( node->parent );
		// this line is just to speed up subsequent finds by keeping the tree depth low:
		node->parent = root;
		return root;
	}
}
