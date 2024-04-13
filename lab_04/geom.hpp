#ifndef GEOM_HPP_INCLUDED
#define GEOM_HPP_INCLUDED
#include "circle.hpp"
#include "point.hpp"
#include "quadr.hpp"

namespace geometry {
	double angle_betw_vec(geomerty::point::Point v1, geomerty::point::Point v2);
	double dist_betw_points(geomerty::point::Point p1, geomerty::point::Point p2);
	double dist_betw_point_segment(geomerty::point::Point c, geomerty::point::Point p1, geomerty::point::Point p2);
	void position_quard_about_circle(geometry::circle::Circle c, geometry::quadr::Quadr q);
	bool four_points_are_collinear(geometry::quadr::Quadr q);
	bool three_points_are_collinear(geomerty::point::Point p1, geomerty::point::Point p2, geomerty::point::Point p3);
}

#endif // GEOM_HPP_INCLUDED;
