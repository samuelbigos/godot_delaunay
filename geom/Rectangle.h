/*
 * Rectangle.h
 *
 *  Created on: 06.03.2013
 *
 */

#ifndef DELAUNAY_RECTANGLE_H_
#define DELAUNAY_RECTANGLE_H_

class Rectangle
{
public:
	Rectangle( float, float, float, float);
	Rectangle( const Rectangle& );
	~Rectangle( );


	inline float bottom() const
	{
		return Y + Height;
	}

	inline float left() const
	{
		return X;
	}

	inline float right() const
	{
		return X + Width;
	}

	inline float top() const
	{
		return Y;
	}

	inline float x() const
	{
		return X;
	}

	inline float y() const
	{
		return Y;
	}

	inline float width() const
	{
		return Width;
	}

	inline float height() const
	{
		return Height;
	}

private:
	float X, Y, Width, Height;
};

#endif /* DELAUNAY_RECTANGLE_H_ */
