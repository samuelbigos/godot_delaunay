/*
 * LR.cpp
 *
 *  Created on: 07.03.2013
 *
 */

#include "LR.h"

namespace LR
{
	enum Side other( enum Side leftRight )
	{
		return leftRight == LEFT ? RIGHT : LEFT;
	}
}
