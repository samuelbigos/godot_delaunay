#ifndef VORONOI_DIAGRAM_H
#define VORONOI_DIAGRAM_H

#include "core/image.h"
#include "core/reference.h"
#include "scene/resources/texture.h"

#include "delaunay/Voronoi.h"

class VoronoiDiagram : public Resource {

	GDCLASS(VoronoiDiagram, Resource);
	OBJ_SAVE_TYPE(VoronoiDiagram);

	Vector2 size;

public:
	VoronoiDiagram();
	~VoronoiDiagram();

	void set_points(const Array &p_points);
	Array get_edges();

	void set_size(const Vector2& p_size);
	Vector2 get_size() const { return size; }	

protected:
	static void _bind_methods();

private:
	Voronoi *_voronoi;
};

#endif // OPEN_SIMPLEX_NOISE_H
