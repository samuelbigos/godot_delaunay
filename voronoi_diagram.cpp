#include "voronoi_diagram.h"

#include "delaunay/Edge.h"

VoronoiDiagram::VoronoiDiagram() :
		_voronoi(nullptr) {

	size = Vector2(0.0, 0.0);
}

VoronoiDiagram::~VoronoiDiagram() {
}

void VoronoiDiagram::set_points(const Array &p_points) {

	if (_voronoi) {
		delete _voronoi;
	}

	std::vector<Point *> v_points;
	std::vector<unsigned int> v_colours;

	for (int i = 0; i < p_points.size(); i++) {

		Vector2 point = p_points[i];
		v_points.push_back(Point::create(point.x, point.y));
		v_colours.push_back(0);
	}
	
	Rectangle plot_bounds(0.0f, 0.0f, size.x, size.y);

	_voronoi = new Voronoi(v_points, &v_colours, plot_bounds);

	std::vector<Edge*> const edges = _voronoi->edges();
	for (int i = 0; i < edges.size(); i++) {

		Edge *edge = edges[i];
		Point const *p0 = edge->voronoiEdge()->p0;
		Point const *p1 = edge->voronoiEdge()->p1;

		if (p0 && p1)
			printf("edge %d: [%f, %f] [%f, %f]", i, p0->x, p0->y, p1->x, p1->y);
	}
}

Array VoronoiDiagram::get_edges() {

	if (_voronoi == nullptr) {

		return Array();
	}

	Array ret;
	std::vector<Edge *> const edges = _voronoi->edges();
	for (int i = 0; i < edges.size(); i++) {

		Edge *edge = edges[i];
		Point const *p0 = edge->voronoiEdge()->p0;
		Point const *p1 = edge->voronoiEdge()->p1;

		if (p0 == nullptr || p1 == nullptr)
			continue;

		ret.append(Vector2(p0->x, p0->y));
		ret.append(Vector2(p1->x, p1->y));
	}

	return ret;
}

void VoronoiDiagram::set_size(Vector2 const &p_size) {

	size = p_size;
}

void VoronoiDiagram::_bind_methods() {

	ClassDB::bind_method(D_METHOD("set_points", "points"), &VoronoiDiagram::set_points);
	ClassDB::bind_method(D_METHOD("get_edges"), &VoronoiDiagram::get_edges);

	ClassDB::bind_method(D_METHOD("set_size", "size"), &VoronoiDiagram::set_size);
	ClassDB::bind_method(D_METHOD("get_size"), &VoronoiDiagram::get_size);

	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "size"), "set_size", "get_size");
}
