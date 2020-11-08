/* register_types.cpp */

#include "register_types.h"
#include "voronoi_diagram.h"

#include "core/class_db.h"

void register_cppdelaunay_types() {
	ClassDB::register_class<VoronoiDiagram>();
}

void unregister_cppdelaunay_types() {
	// Nothing to do here in this example.
}
