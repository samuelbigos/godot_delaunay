/*
 * LR.h
 *
 *  Created on: 06.03.2013
 *
 */

#ifndef DELAUNAY_LR_H_
#define DELAUNAY_LR_H_

namespace LR
{
	enum Side {
		LEFT = 0, RIGHT
	};

	enum Side other( enum Side leftRight );
};

#endif /* DELAUNAY_LR_H_ */
